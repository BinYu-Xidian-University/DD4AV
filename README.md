# DD4AV: Efficient Atomicity Violation Detection for Interrupt-driven Programs via Schedule Prefixes

DD4AV is a dynamically controlled scheduling testing tool, where a scheduler explores the space of possible interleavings of  interrupt-driven programs looking for atomicity violations.

This repository provides the tool and the evaluation subjects for the paper "Efficient Atomicity Violation Detection for
Interrupt-driven Programs via Schedule Prefixes"

**Table of contents**
- [Directory Structure](#directory-structure)
- [Tool](#tool)
  - [Requirements](#requirements)
  - [Installing](#installing)
- [Test](#test)
  
----------


## Directory Structure

The repository mainly contains three folders: [*tool*](#tool) and [*test*](#test). We briefly introduce each folder under `/workdir/DD4AV`: 
- `clang+llvm`: Pre-Built Binaries of LLVM 10.0. These binaries include Clang, LLD, compiler-rt, various LLVM tools, etc.
- `tools`: Root directory for DD4AV tool and scripts.
  - `DBDS`: The code about our proposed periodical scheduling method that can systematically explore the thread interleaving.
  - `staticanalysis`: The scripts of static analysis, which aim to find key points that used to be scheduled during testing. It also contains the codes about instrumentation.
  - `SVF`: Third-party libraries project SVF, which provides interprocedural dependence analysis for LLVM-based languages. SVF is able to perform pointer alias analysis, memory SSA form construction, value-flow tracking for program variables. 
  - `wllvm`: Third-party libraries project WLLVM, which provides tools for building whole-program (or whole-library) LLVM bitcode files from an unmodified C or C++ source package.
- `test`: Some simple examples that are easy to understand. These examples could also be used to check the installation.

----------

## Tool

### Requirements
If you want to install the tool from source code on your host system, please ensure that your environment meets the following requirements. 

- **Operating System:** >= Ubuntu 18.04 LTS (Requires kernel version >= 4.x due to the scheduling policy)


### Installing
- **install Package:**: Our artifact depends on some packages, please run the following command to install required packages.

  ```sh
    sudo apt-get install -y wget git build-essential libtinfo5 python3 python python3-pip tmux cmake libtool libtool-bin automake autoconf autotools-dev m4 autopoint libboost-dev help2man gnulib bison flex texinfo zlib1g-dev libexpat1-dev libfreetype6 libfreetype6-dev libbz2-dev liblzo2-dev libtinfo-dev libssl-dev pkg-config libswscale-dev libarchive-dev liblzma-dev liblz4-dev doxygen vim intltool gcc-multilib sudo --fix-missing
  ```
  
  ```sh
    pip install numpy && pip3 install numpy && pip3 install sysv_ipc
  ```
- **Download the code**

    Download the DD4AV from figshare to the local computer and enter the project directory
    ```sh
    cd DD4AV
    ```

- **Configure the environment and install the tool.**

    For simplicity, we provide shell scripts for the whole installation. Run the following command to automatically configure the environment and install the tool.
    
    ```sh
    # install LLVM and clang
    tool/install_llvm.sh

    # set up environment
    source tool/init_env.sh

    # install SVF
    $ROOT_DIR/tool/install_SVF.sh

    # install static analysis tool
    $ROOT_DIR/tool/install_staticAnalysis.sh

    # install wllvm
    sudo pip install -e $ROOT_DIR/tool/wllvm/
    ```

- **Usage**
	
	Everytime you open a new terminal you need to set up an environment variable.

	```sh
	# set up environment
    source tool/init_env.sh
	```

----------

## Test

Before you use DD4AV, we suggest that you first use those simple examples provided by us to confirm whether the tool can work normally. In the following, we use the examples in the `test` folder to explain how to use the tool.

You can use one of the programs in the `test` folder to check whether DD4AV works normally. Take [`motivating_example`](test/motivating_example/df.c) as a running example. Here, let's run it with a prepared script.

1. Enter the working directory:
    ```sh
    cd /DD4AV/test/motivating_example
    ```

2. Use the following script to build the program:
   ```sh
   ./cleanDIR.sh && ./build.sh
   ```

3. Perform systematic controlled concurrency testing based on periodical scheduling:
    ```sh
    $ROOT_DIR/tool/DBDS/run.py -y -d 5 ./motivating_example
    ```

4. If DD4AV works normally, you can see the following outputs, which indicate that DD4AV reports 2 buggy interleavings in this program (i.e., double free bugs):
    ```sh
    Start Testing!
    There is no schedule to satisfy under the constraint: [3, 2, 1] ,  2
    Targeting bugs that bug depth = 1 . Iterate for 2 periods
    Targeting bugs that bug depth = 2 . Iterate for 3 periods
    test 0001: [[0, 0, 0], [1, 1], [2]]
    test 0002: [[0, 0, 0], [2], [1, 1]]
    test 0003: [[1, 1], [0, 0, 0], [2]]
    test 0004: [[1, 1], [2], [0, 0, 0]]
    test 0005: [[2], [0, 0, 0], [1, 1]]
    test 0006: [[2], [1, 1], [0, 0, 0]]
    Targeting bugs that bug depth = 3 . Iterate for 4 periods
    test 0007: [[0], [1, 1], [0, 0], [2]]
    test 0008: [[0, 0], [1, 1], [0], [2]]
    test 0009: [[0], [1, 1], [2], [0, 0]]
    test 0010: [[0, 0], [1, 1], [2], [0]]
    test 0011: [[0, 0, 0], [1], [2], [1]]
    test 0012: [[0], [2], [0, 0], [1, 1]]
    test 0013: [[0, 0], [2], [0], [1, 1]]
    test 0014: [[0], [2], [1, 1], [0, 0]]
    test 0015: [[0, 0], [2], [1, 1], [0]]
    test 0016: [[1, 1], [0], [2], [0, 0]]
    test 0017: [[1, 1], [0, 0], [2], [0]]
    test 0018: [[1], [2], [1], [0, 0, 0]]
    test 0019: [[2], [0], [1, 1], [0, 0]]
    test 0020: [[2], [0, 0], [1, 1], [0]]
    Targeting bugs that bug depth = 4 . Iterate for 5 periods
    test 0021: [[0], [1, 1], [0], [2], [0]]
    test 0022: [[0], [1], [2], [1], [0, 0]]
    test 0023: [[0, 0], [1], [2], [1], [0]]
    test 0024: [[0], [2], [0], [1, 1], [0]]
    There is no schedule to satisfy under the constraint: [3, 2, 1] ,  6
    Targeting bugs that bug depth = 5 . Iterate for 6 periods
    End Testing!

    --------------------------------------------------
    (('W', 10), ('R', 17), ('W', 12))
    (('W', 10), ('R', 23), ('W', 12))
    Total Round: 24
    First_buggy_round: 7		Total_buggy_rounds: 16	Total_rounds: 24
    bugDepth: 5
    AtomicityViolationTime	00:00:00.03818
    ```
   
5. If the above steps can be executed normally, it means that your installation has been successful! You can continue to try other examples in the `test` folder.

----------

