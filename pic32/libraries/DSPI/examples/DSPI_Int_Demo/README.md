DSPI_Int_Demo Readme

This demo sketch simply shows how to use multiple SPI ports
on the same chipKIT board with the DSPI library, but doing the
transfers at the same time using interrupts.

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

Three data output buffers and three data input buffers are created.
Different data is sent out each SPI port, at different speeds.
Each transaction is started at about the same time using interrupts
(intTransfer()). The code then waits until all three transfers have
completed, and prints out the data received from each port.

Expected Output:

You should see "11:22:33  44:55:66  77:88:99".