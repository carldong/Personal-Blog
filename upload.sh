#!/bin/bash

#ssh dongr2@clark.server.rpi.edu
#scp -r _site/* dongr2@clark.server.rpi.edu:/home/43/dongr2/public_html/
./build.sh
rsync --protocol=29 -az --progress --delete _site/ dongr2@clark.server.rpi.edu:/home/43/dongr2/public_html/
