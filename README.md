# moos-dawg-static-analysis-examples

These are the examples from the MOOS-DAWG 2019 Talk "Leveraging the Compiler: Static Analysis in Marine Robotic Systems".

These were tested on Ubuntu 18.04, other distros will likely require modification to the CMakeLists.txt.

To run you will need to install Goby3:
```
echo "deb http://packages.gobysoft.org/ubuntu/release/ `lsb_release -c -s`/" | sudo tee /etc/apt/sources.list.d/gobysoft_release.list && sudo apt-key adv --recv-key --keyserver keyserver.ubuntu.com 19478082E2F8D3FE
sudo apt-get update
sudo apt-get install libgoby3-dev
```

You also need the `goby_clang_tool` repository (which may eventually be merged into Goby3 itself):
```
git clone https://github.com/GobySoft/goby3-clang
sudo apt install libyaml-cpp-dev clang libclang-dev
mkdir build
cmake ..
make
# Add goby3-clang/build to your $PATH variable or do a "make install"
```

If you want to use Cling for the units example, see the installation instructions here: https://cdn.rawgit.com/root-project/cling/master/www/index.html
