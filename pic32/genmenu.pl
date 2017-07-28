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
    $in =~ s/[\r\n]//g;
    if ($in =~ /^([^#]+)\.usb.enabled\s*=\s*true/) {
        $boards{$1}->{enabled} = 1;
    }
    if ($in =~ /^([^#]+)\.usb.default\s*=\s*(.*)/) {
        $boards{$1}->{default} = $2;
    }
}
close(IN);

print Dumper(%boards);

print OUT "\r\n";
foreach my $board (keys %boards) {
    my $defprof = $boards{$board}->{default};
    print OUT "${board}.menu.USB.${defprof}=" . $profiles{$defprof}->{name} . "\r\n";
    print OUT "${board}.menu.USB.${defprof}.build.extra_flags=" . $profiles{$defprof}->{flags} . "\r\n";

    foreach my $prof (sort keys %profiles) {
        if ($prof eq $defprof) {
            next;
        }
        print OUT "${board}.menu.USB.${prof}=" . $profiles{$prof}->{name} . "\r\n";
        print OUT "${board}.menu.USB.${prof}.build.extra_flags=" . $profiles{$prof}->{flags} . "\r\n";
    }
    print OUT "\r\n"

}

close(OUT);

copy("boards.txt", "boards.bak");
copy(".boards.txt~", "boards.txt");
unlink(".boards.txt~");
