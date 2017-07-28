#!/usr/bin/perl

###########################################################
#
# Small perl script to generate the menu entries for boards
# that want them. Any board with a -D_USE_USB_FOR_SERIAL_
# extra flags entry will be automatically included.
#
###########################################################

use strict;

use Data::Dumper;
use File::Copy;

my %boards;

my %profiles;
$profiles{a_cdcacm}->{name} = "Serial";
$profiles{a_cdcacm}->{flags} = "-D__USB_ENABLED__ -D__USB_CDCACM__ -D__SERIAL_IS_USB__";

$profiles{b_cdcacm_km}->{name} = "Serial, Keyboard & Mouse";
$profiles{b_cdcacm_km}->{flags} = "-D__USB_ENABLED__ -D__USB_CDCACM_KM__ -D__SERIAL_IS_USB__";

$profiles{z_custom}->{name} = "Custom / Disabled";
$profiles{z_custom}->{flags} = "";


open(IN, "<boards.txt") || die "Cannot open boards.txt";
open(OUT, ">.boards.txt~") || die "Cannot open temporary work file";
while (my $in = <IN>) {
    print OUT $in;
    if ($in =~ / DO NOT ADD ANYTHING AFTER THIS LINE /) {
        last;
    }
    if ($in =~ /^([^#]+)\.build\.extra_flags=-D_USE_USB_FOR_SERIAL_/) {
        $boards{$1} = 1;
    }
}
close(IN);

print OUT "\r\n";
foreach my $board (keys %boards) {

    foreach my $prof (sort keys %profiles) {
        print OUT "${board}.menu.USB.${prof}=" . $profiles{$prof}->{name} . "\r\n";
        print OUT "${board}.menu.USB.${prof}.build.extra_flags=" . $profiles{$prof}->{flags} . "\r\n";
    }
    print OUT "\r\n"

}

close(OUT);

copy("boards.txt", "boards.bak");
copy(".boards.txt~", "boards.txt");
unlink(".boards.txt~");
