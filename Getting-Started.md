Here is how to get started with OpenSWE1R development using the Star Wars Episode 1: Racer demo.

## Installing the demo version

1. Follow the [[Build Instructions]] to build OpenSWE1R for your platform.

2. Acquire the Windows webdemo installer ("racerdemo.exe") and copy it to your "build/" folder.
[[Webdemo download links can be found here|Game Versions]]. Its md5sum should be `f5c003fa7f7f6b0dc4b10f5e1d89c293`.

3. Find "cabextract" for your platform.
It is available on most platforms package manager, but [can also be downloaded from its official website](https://www.cabextract.org.uk/).

4. Run `cabextract -L racerdemo.exe` to extract the games files. All files will automatically be converted to lowercase. You don't need "racerdemo.exe" anymore after this step, so it can be deleted.

5. Run your previously built "openswe1r" binary to start the game.

You should have a working installation of OpenSWE1R now.