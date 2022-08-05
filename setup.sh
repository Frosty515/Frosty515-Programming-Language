#!/bin/sh

echo '---------------------'
echo 'Frosty515 Programming Language'
echo '---------------------'
echo ' '

echo 'Checking for neccessary programs.'

if ! [ -x "$(command -v git)" ]; then
  echo 'Error: git is not installed.'
  exit 1
fi

if ! [ -x "$(command -v wx-config)" ]; then
  echo 'Error: wx-config is not installed.'
  exit 1
fi

if ! [ -x "$(command -v gcc)" ]; then
  echo 'Error: gcc is not installed.'
  exit 1
fi

if ! [ -x "$(command -v g++)" ]; then
  echo 'Error: g++ is not installed.'
  exit 1
fi

if ! [ -x "$(command -v ld)" ]; then
  echo 'Error: ld is not installed.'
  exit 1
fi

if ! [ -x "$(command -v rm)" ]; then
  echo 'Error: rm is missing.'
  exit 1
fi

echo 'Done. All programs found.'

echo '---------------------'

echo ' '

echo 'Resolving Dependencies.'

mkdir -p ./vendor/bin

mkdir ./vendor/bin/premake
mv ./.depend/premake/* ./vendor/bin/premake

rm -fr .depend

echo 'Done.'

echo '---------------------'
echo ' '

echo 'Creating scripts.'

mv ./.Scripts/premake5.lua .
mv ./.Scripts/Windows/* .
mv ./.Scripts/Linux/* .

rm -fr ./.Scripts

echo 'Done.'
echo '---------------------'

echo ' '

echo 'Read README.md for info on building and running.'

exit 0