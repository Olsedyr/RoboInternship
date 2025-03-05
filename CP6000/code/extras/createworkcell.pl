#!/usr/bin/perl
#
# Script copies one workcell to another (new one) in same MPN database
#
# Made by Mads Lundstrøm <mil@mpnrobotics.com> 16.08.2005
#
use strict;                        # important pragma
use warnings;                      # another important pragma

my $database;
my $fromworkcell;
my $toworkcell;
my $temp;

print "Path to database? ";
$database = <STDIN>;               # ask for the database-path
chomp($database);                  # remove "new line"

until ((-d $database)&&(-d "$database/workcell")&&(-d "$database/system")&&(-d "$database/robot")&&(-d "$database/plant")&&($database =~ /.*database$/)) 
{
    $temp=`pwd`; 
    chomp($temp); 
    $database=$temp.$database; 
    if(!((-d $database)&&(-d "$database/workcell")&&(-d "$database/system")&&(-d "$database/robot")&&(-d "$database/plant")&&($database =~ /.*database$/))) 
    { 
      print "Database directory \"$database\" not found. Please give correct path: ";
      $database = <STDIN>;               # ask for the database-path again
      chomp($database);                  # remove "new line"
    }
}

print "Copy from plant/workcell? ";
$fromworkcell = <STDIN>;           # ask for the workcell to copy from
chomp($fromworkcell);              # remove "new line"

until ((-f "$database/workcell/$fromworkcell.workcell")&&(-f "$database/plant/$fromworkcell.plant")) {
    print "Workcell with name $fromworkcell not found. Please provide another name: ";
    $fromworkcell = <STDIN>;               # ask for the fromworkcell again
    chomp($fromworkcell);                  # remove "new line"
}

print "New plant/workcell-name? ";
$toworkcell = <STDIN>;           # ask for the new workcell name
chomp($toworkcell);              # remove "new line"


while ((-f "$database/workcell/$toworkcell.workcell")||(-f "$database/plant/$toworkcell.plant")||(-f "$database/robot/$toworkcell.robot")) {
    print "Workcell with name $toworkcell apparently already exists. Please provide another name: ";
    $toworkcell = <STDIN>;               # ask for toworkcell again
    chomp($toworkcell);                  # remove "new line"
}

print "Making new plant/workcell $toworkcell using workcell $fromworkcell as skeleton. Using database at \"$database\"...\n";

my @lines;
my $indir;
my $infile;

opendir (INPUTDIR, $database) || die "Cannot open \"$database\" directory\n";

while ($indir = readdir (INPUTDIR)) { 
    chomp $indir;
    opendir(INDIR, "$database/$indir") || die "can't open $indir.\n";
    while ($infile = readdir (INDIR)) { 
	my $outfile = $infile;
	$outfile =~ s/$fromworkcell/$toworkcell/g;
	if ($infile =~ /^$fromworkcell.*\.$indir$/) { 
	    open(INFILE, "$database/$indir/$infile") || die "can't open $infile for reading.\n";
	    print "copying $indir/$infile to $indir/$outfile\n";    
	    @lines = <INFILE>;
	    close INFILE;
	    for (my $i=0;$i<@lines;$i++) {
		$lines[$i] =~ s/$fromworkcell/$toworkcell/g;
	    }
	    open(OUTFILE,">$database/$indir/$outfile") || die "Couldn't open/create the file $indir/$outfile. Exiting.\n";
	    print OUTFILE @lines;
	    close(OUTFILE);
	} 
	elsif (($infile =~ /^$fromworkcell.*/)&&($infile !~ /\~$/)) {
	    print "Program in doubt. Should we copy $infile to new file $outfile? ([y]es/[n]o): ";
	    my $answer = <STDIN>; 
	    chomp($answer);    
	    if ($answer =~ /(y|Y).*/) {
		open(INFILE, "$database/$indir/$infile") || die "can't open $infile for reading.\n";
		print "copying $indir/$infile to $indir/$outfile\n";    
		@lines = <INFILE>;
		close INFILE;
		for (my $i=0;$i<@lines;$i++) {
		    $lines[$i] =~ s/$fromworkcell/$toworkcell/g;
		}
		open(OUTFILE,">$database/$indir/$outfile") || die "Couldn't open/create the file $indir/$outfile. Exiting.\n";
		print OUTFILE @lines;
		close(OUTFILE);
	    }
	}
    }
    closedir(INDIR);
}
print "Done!\n"
