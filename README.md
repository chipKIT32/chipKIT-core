# chipkit-core
Downloadable chipKIT core for use with Arduino 1.6x IDE and UECIDE
## Build Requirements

* [ANT](http://ant.apache.org/)

## Build Instructions

```
ant setup
ant build
ant macosx-build
ant windows-build
ant linux32-build
ant linux64-build
ant raspberrypi-build
ant clean
ant updatepic32prog

ant dist //compress the builds prepare for deployment
```

## Deployment instructions
* The path is OS specific.
* The user sketch folder needs a folder called hardware.
```
Copy from dist OS Platform and move to ~/Documents/Arduino/hardware folder
```
