#!/usr/bin/perl

use strict;

use Data::Dumper;

my $csv = shift || die("Usage: makechips.pl <csv file>");
open(CSV, "< $csv") || die("Unable to open $csv");
my $header = <CSV>;
chomp($header);
my @fields = split(/,/, $header);

my @fieldnames;

my $chipdata;

foreach my $f (@fields) {
    if ($f =~ /"(.*)"/) {
        $f = $1;
    }
    push(@fieldnames, $f);
}

while (my $line = <CSV>) {
    my @entries = split(/,/, $line);
    my $i = 0;
    my $cd;
    foreach my $entry (@entries) {
        if ($entry =~ /"(.*)"/) {
            $entry = $1;
        }
        $entry =~  s/^\s+|\s+$//g;
        $cd->{$fieldnames[$i]} = $entry;
        $i++;
    }
    $chipdata->{$cd->{Product}} = $cd;
}

close (CSV);


my $first = 1;

foreach my $chip (sort keys %{$chipdata}) {
    if ($chipdata->{$chip}->{'CPU Type'} == '32-bit MIPS MCU') {

        my $cname = $chip;
        $cname =~ s/^PIC//g;
        if ($first == 1) {
            print "#if defined(__" . $cname . "__)\n";
            $first = 0;
        } else {
            print "#elif defined(__" . $cname . "__)\n";
        }

        my $ram = $chipdata->{$chip}->{'RAM (KB)'};
        my $ddr = 0;

        if ($ram > 32000) {
            $ddr = int($ram / 1000);
            $ram = $ram - 32000;
        }

        my $fam = makeFamily($cname);


        print "    #define _CPU_NAME_                    \"$cname\"\n";
        print "    #define FLASHEND                      (((" . $chipdata->{$chip}->{'Program Memory Size (KB)'} . " - 4) * 1024L) - 1)\n";
        print "    #define RAMEND                        (($ram * 1024L) - 1)\n";

        if ($chipdata->{$chip}->{'Peripheral Pin Select / Pin Muxing'} eq "Yes") {
            print "    #define __PIC32_PPS__\n";
        }
        
        print "    #define __PIC32_PINS__                " . $chipdata->{$chip}->{'Pin count'} . "\n";
        if ($cname =~ /^32MZ(\d+)EF/) {
            print "    #define __PIC32MZEFADC__\n";
        }

        print "    #define __" . $fam . "__\n";

        if ($cname =~ /^32MX(\d)70F(\d+)([HL])$/) {
            print "    #define __PIC32MX" . $1 . "7X" . $3 . "__\n";
        }

        if ($chipdata->{$chip}->{'DRAM Interface'} eq "DDR2") { # External DDR
            print "    #define __HAS_DDR_EXTERNAL__\n";
        } elsif (($chipdata->{$chip}->{'DRAM Interface'} eq "") && ($ddr > 0)) { # Internal DDR
            print "    #define __HAS_DDR_INTERNAL__\n";
            print "    #define __DDR_SIZE__                  ($ddr * 1024 * 1204)\n";
        }

        if ($chipdata->{$chip}->{'Crypto Engine'} eq "Yes") {
            print "    #define __HAS_CRYPTO__\n";
        }

        if ($chipdata->{$chip}->{'USB Interface'} ne "No") {
            print "    #define __HAS_USB__\n";
            print "    #define __NUM_USB_MODULES__           " . $chipdata->{$chip}->{'Number of USB Modules'} . "\n";
        }

        if ($chipdata->{$chip}->{'Graphics Controller/GPU'} ne 'No') {
            print "    #define __HAS_GPU__\n";
        }

        if ($chipdata->{$chip}->{'Direct Memory Access Channels'} > 0) {
            print "    #define __HAS_DMA__\n";
            print "    #define __NUM_DMA_CHANNELS__          " . $chipdata->{$chip}->{'Direct Memory Access Channels'} . "\n";
        }

        if ($chipdata->{$chip}->{'Ethernet'} ne "None") {
            print "    #define __HAS_ETHERNET__\n";
        }

        print "    #define __FLASH_ROW__                 " . flashRow($fam) . "\n";
        print "    #define __FLASH_PAGE__                " . flashPage($fam) . "\n";


        print "\n";
    }
}

print "#else\n";
print "    #error CPU type is unknown, cpudefs.h needs to have additions\n";

print "#endif\n";

#print Dumper($chipdata);


sub makeFamily($) {
    my $cname = shift;

    if ($cname =~ /^32MZ/) {
        return "PIC32MZXX";
    }

    if ($cname =~ /^32MX1/) {
        return "PIC32MX1XX";
    }

    if ($cname =~ /^32MX2/) {
        return "PIC32MX2XX";
    }

    if ($cname =~ /^32MX33/) {
        return "PIC32MX37X";
    }

    if ($cname =~ /^32MX35/) {
        return "PIC32MX37X";
    }

    if ($cname =~ /^32MX37/) {
        return "PIC32MX37X";
    }

    if ($cname =~ /^32MX43/) {
        return "PIC32MX47X";
    }

    if ($cname =~ /^32MX45/) {
        return "PIC32MX47X";
    }

    if ($cname =~ /^32MX47/) {
        return "PIC32MX47X";
    }

    if ($cname =~ /^32MX3/) {
        return "PIC32MX3XX";
    }

    if ($cname =~ /^32MX4/) {
        return "PIC32MX4XX";
    }

    if ($cname =~ /^32MX5/) {
        return "PIC32MX5XX";
    }

    if ($cname =~ /^32MX6/) {
        return "PIC32MX6XX";
    }

    if ($cname =~ /^32MX7/) {
        return "PIC32MX7XX";
    }

    return "PIC" . substr($cname, 0, 4) . "XX";
}

sub flashRow($) {
    my $f = shift;

    if ($f eq "PIC32MX1XX") {
        return 128;
    }

    if ($f eq "PIC32MX2XX") {
        return 128;
    }

    if ($f eq "PIC32MX3XX") {
        return 512;
    }

    if ($f eq "PIC32MX38X") {
        return 512;
    }

    if ($f eq "PIC32MX4XX") {
        return 512;
    }

    if ($f eq "PIC32MX47X") {
        return 512;
    }

    if ($f eq "PIC32MX5XX") {
        return 512;
    }

    if ($f eq "PIC32MX6XX") {
        return 512;
    }

    if ($f eq "PIC32MX7XX") {
        return 512;
    }

    if ($f eq "PIC32MZXX") {
        return 512;
    }

    if ($f eq "PIC32MKXX") {
        return 512;
    }

    if ($f eq "PIC32MMXX") {
        return 256;
    }

    return 512;
}


sub flashPage($) {
    my $f = shift;

    if ($f eq "PIC32MX1XX") {
        return 1024;
    }

    if ($f eq "PIC32MX2XX") {
        return 1024;
    }

    if ($f eq "PIC32MX3XX") {
        return 4096;
    }

    if ($f eq "PIC32MX38X") {
        return 4096;
    }

    if ($f eq "PIC32MX4XX") {
        return 4096;
    }

    if ($f eq "PIC32MX47X") {
        return 4096;
    }

    if ($f eq "PIC32MX5XX") {
        return 4096;
    }

    if ($f eq "PIC32MX6XX") {
        return 4096;
    }

    if ($f eq "PIC32MX7XX") {
        return 4096;
    }

    if ($f eq "PIC32MZXX") {
        return 4096;
    }

    if ($f eq "PIC32MKXX") {
        return 4096;
    }

    if ($f eq "PIC32MMXX") {
        return 2048;
    }

    return 4096;
}


