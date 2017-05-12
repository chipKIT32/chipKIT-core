DSPI_Demo Readme

This demo sketch simply shows how to use multiple SPI ports
on the same chipKIT board with the DSPI library.

Setup:

This sketch assumes that your chipKIT board has at least 3 SPI ports,
and that each SPI port's MOSI is connected to its MISO. This 'loopback'
configuration simply sends data out and receives it back in again. 

Each of the three SPI ports is set to a different clock speed so that
it is clear which is which on the logic analyzer trace.

This sketch is set up for the Fubarino SD board, but it can easily 
be adopted to any chipKIT board by changing the number of DSPI objects
and the chip select pins (if necessary - it's fine to leave them
at their default values too).

Flow:

Data is sent out DSPI0, then received back in DSPI0. That received
data is then sent out DSPI1, received back in DSPI1, then that received
data is sent out DSPI2, received back in DSPI2, then printed out
to the USB serial port to the PC. If there are any errors, you will not
see the proper printout in the serial monitor.

Expected Output:

You should see "55:AA:A5  55:AA:A5  55:AA:A5".