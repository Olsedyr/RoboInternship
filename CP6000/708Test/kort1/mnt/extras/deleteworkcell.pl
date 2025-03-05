#!/usr/bin/perl
#
# Script deletes a workcell in MPN database 
#
# Made by Mads Lundstrøm <mil@mpnrobotics.com> 16.08.2005
#
use strict;                        # important pragma
use warnings;                      # another important pragma

my $database;
my $workcell;

print "Path to database? ";
$database = <STDIN>;               # ask for the database-path
chomp($database);                  # remove "new line"

until ((-d $database)&&(-d "$database/workcell")&&(-d "$database/system")&&(-d "$database/plant")&&($database =~ /.*database$/)) {
    print "Database directory \"$database\" not found. Please give correct path: ";
    $database = <STDIN>;               # ask for the database-path again
    chomp($database);                  # remove "new line"
}

print "plant/workcell to delete? ";
$workcell = <STDIN>;           # ask for the workcell to delete
chomp($workcell);              # remove "new line"

until ((-f "$database/workcell/$workcell.workcell")&&(-f "$database/plant/$workcell.plant")) {
    print "Workcell with name $workcell not found. Please provide another name: ";
    $workcell = <STDIN>;               # ask for the workcell again
    chomp($workcell);                  # remove "new line"
}
print "Deleting plant/workcell $workcell in database at \"$database\". Is this really what you want? ([y]es/[n]o): ";
my $answer = <STDIN>; 
chomp($answer);    
if ($answer !~ /(y|Y).*/) {
    die "Nothing was deleted.\n";
}

my $indir;
my $infile;

opendir (INPUTDIR, $database) || die "Cannot open \"$database\" directory\n";

while ($indir = readdir (INPUTDIR)) { 
    chomp $indir;
    opendir(INDIR, "$database/$indir") || die "can't open $indir.\n";
    while ($infile = readdir (INDIR)) { 
	if ($infile =~ /^$workcell.*\.$indir$/) { 
	    print "deleting $indir/$infile...\n"; 
	    unlink("$database/$indir/$infile");
	} 
	elsif ($infile =~ /^$workcell.*/) {
	    print "Program in doubt. Should $indir/$infile be deleted? ([y]es/[n]o): ";
	    my $answer = <STDIN>; 
	    chomp($answer);    
	    if ($answer =~ /(y|Y).*/) {
		print "deleting $indir/$infile...\n"; 
		unlink("$database/$indir/$infile");  
	    }
	}
    }
    closedir(INDIR);
}    
print "Done!\n"
