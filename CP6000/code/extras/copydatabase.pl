#!/usr/bin/perl
#
# Script copies a MPN database to a new location containing only one workcell. 
#
# Made by Mads Lundstrøm <mil@mpnrobotics.com> 16.08.2005
#

use strict;                        # important pragma
use warnings;                      # another important pragma

my $database;
my $dbpath;
my $newdbname = "database";
my $workcell;

print "Path to source database? ";
$database = <STDIN>;               # ask for the database-path
chomp($database);                  # remove "new line"

until ((-d $database)&&(-d "$database/workcell")&&(-d "$database/system")&&(-d "$database/robot")&&(-d "$database/plant")&&($database =~ /.*database$/)) {
    print "Database directory \"$database\" not found. Please give correct path: ";
    $database = <STDIN>;               # ask for the database-path again
    chomp($database);                  # remove "new line"
}

print "Path where new database-structure should reside? ";
$dbpath = <STDIN>;             # ask for the new database-path
chomp($dbpath);                # remove "new line"

until (-d $dbpath) {
    print "Path unknown. Please give valid path: ";
    $dbpath = <STDIN>;               # ask for the new database-path again
    chomp($dbpath);                  # remove "new line"
}

while (-d "$dbpath/$newdbname") {
    print "Directory \"$newdbname\" alreade exists at \"$dbpath\". Please give another name for dir: ";
    $newdbname = <STDIN>;               # ask for the database-path again
    chomp($newdbname);                  # remove "new line"
}

print "plant/workcell to copy to new database location? ";
$workcell = <STDIN>;           # ask for the workcell 
chomp($workcell);              # remove "new line"

until ((-f "$database/workcell/$workcell.workcell")&&(-f "$database/plant/$workcell.plant")&&(-f "$database/robot/$workcell.robot")) {
    print "Workcell with name $workcell not found. Please provide another name: ";
    $workcell = <STDIN>;               # ask for the workcell again
    chomp($workcell);                  # remove "new line"
}

print "Copying databasestructure from location \"$database\ to location \"$dbpath/$newdbname\". Is this really what you want? ([y]es/[n]o): ";
my $answer = <STDIN>; 
chomp($answer);    
if ($answer !~ /(y|Y).*/) {
    die "Nothing was copied.\n";
}

my $indir;
my $infile;

opendir (INPUTDIR, $database) || die "Cannot open \"$database\" directory\n";
mkdir ("$dbpath/$newdbname",0775) || die "Couldn't create dir \"$dbpath/$newdbname\"\n";
while ($indir = readdir (INPUTDIR)) { 
    chomp $indir;
    if ($indir ne "." and $indir ne "..") {
	opendir(INDIR, "$database/$indir") || die "can't open $indir.\n";
	mkdir ("$dbpath/$newdbname/$indir",0775) || die "Couldn't create dir \"$dbpath/$newdbname/$indir\"\n";
	my $anycopy = 0;
	my @filelist;
	while ($infile = readdir(INDIR)) {
	    if (-f "$database/$indir/$infile") {
		push @filelist,$infile;
	    }
	    if ($infile =~ /^$workcell.*\.$indir$/) { 
		print "copying $indir/$infile to $dbpath/$newdbname/$indir...\n";
		`cp $database/$indir/$infile $dbpath/$newdbname/$indir`;
		$anycopy++;
	    } 
	    elsif (($infile =~ /^$workcell.*/)&&($infile !~ /\~$/)) {
		print "Program in doubt. Should $indir/$infile be copied? ([y]es/[n]o): ";
		my $answer = <STDIN>; 
		chomp($answer);    
		if ($answer =~ /(y|Y).*/) {
		    print "copying $indir/$infile to $dbpath/$newdbname/$indir...\n";
		    `cp $database/$indir/$infile $dbpath/$newdbname/$indir`;
		    $anycopy++;
		}
	    }
	}
	if ($anycopy == 0) {
	    print "No files automatically copied from $database/$indir. Do you wish to copy any files? ([l]ist/[n]o): ";
	    $answer = <STDIN>; 
	    chomp($answer);    
	    if ($answer =~ /(l|L).*/) {
		my @list;
		for (my $i=0;$i<@filelist;$i++) {
		    my $j = $i+1;
		    print "($j) $indir/$filelist[$i]\n";
		}
		print "Give list of files you want to copy (whitespace separated): ";
		$answer = <STDIN>; 
		chomp($answer); 
		@list = split (/\s+/, $answer);
		for (my $i=0;$i<@list;$i++) {
		    if (($list[$i] >= 1)&&($list[$i] <= @filelist)) {
			my $j = $filelist[$list[$i]-1];
			print "copying $indir/$j to $dbpath/$newdbname/$indir...\n";
			`cp $database/$indir/$j $dbpath/$newdbname/$indir`;
		    }
		}
	    }
	}
	closedir(INDIR);
    }    
}
print "Done!\n"
