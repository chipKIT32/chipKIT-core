# chipkit-core
tesssssst
Downloadable chipKIT core for use with Arduino 1.6x IDE and UECIDE
## Build Requirements

* [ANT](http://ant.apache.org/)

## Build Options

```
ant setup
ant build
ant macosx-build
ant windows-build
ant linux32-build
ant linux64-build
ant raspberrypi-build

ant dist //builds, compresses, prepares deployment for current OS
ant dist-all //builds all distributions

ant macosx-dist
ant windows-dist
ant linux32-dist
ant linux64-dist
ant raspberrypi-dist

ant clean //cleans all dist and temp files
ant updatepic32prog
```

## Deployment instructions

Option 1:
* `ant dist`
* copy the dist/{OS} zip file to {SketchFolder}/Arduino/hardware
* unzip the the zip file
* start Arduino
* Boards will be listed in the board drop down

Option 2:
* `ant build`
* copy the dist/{OS} folder  to {SketchFolder}/Arduino/hardware
* The user sketch folder needs a folder called hardware.
* start Arduino
* Boards will be listed in the board drop down

```
Copy from dist OS Platform and move to ~/Documents/Arduino/hardware folder
```
