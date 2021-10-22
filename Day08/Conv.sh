#!/bin/bash
echo "Downloading: $1" 
# https://sv.wikipedia.org/wiki/Volvo_Personvagnar
wget -O volvo.html $1
sed -i 's/Volvo/TheBestCompanyInTheWorld/g' volvo.html
