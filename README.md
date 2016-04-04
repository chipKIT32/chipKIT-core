# chipkit-core
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
* copy the dist/{OS} zip file to {SketchBookFolder}/hardware
* unzip the the zip file
* start Arduino
* Boards will be listed in the board drop down

Option 2:
* `ant build`
* copy the dist/{OS} folder  to {SketchFolder}/Arduino/hardware
* The user sketch folder needs a folder called hardware.
* start Arduino
* Boards will be listed in the board drop down

Note that we now support direct installation from within Arduino v1.6.7 (and up) via the Boards Manager. Simply place this URL

https://raw.githubusercontent.com/chipKIT32/chipKIT-core/master/package_chipkit_index.json

in the Preferences->Additional Boards Manager URLs: text field and then opening up the Boards Manager in the Tools->Board menu. 

See http://chipkit.net/wiki/index.php?title=ChipKIT_core for complete instructions.

```
Copy from dist OS Platform and move to ~/Documents/Arduino/hardware folder
```
