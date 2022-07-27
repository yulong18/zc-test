After building the sub-extensions of ZC* extension, I want to know the difference of the code size between the sub-extensions and baseline.

So I did some works to test the code size with Embench for all sub-extensions of ZC* extension.

I did the following work and got the corresponding results.

1.download Embench

  git clone https://github.com/embench/embench-iot.git
  
2.build toolchain
  
  I used the toolchain that had been built, the download link is as follows.
  
  https://github.com/Liaoshihua/code-size-reduction-gnu-toolchain
  
3.run the build_all.py to compile the embench

  cd embench-iot
  ./build-all.py --arch riscv32 --chip generic --board ri5cyverilator --cc $HOME/zc-test/riscv-gnu-toolchain/opt-riscv-rv32-zca/bin/riscv32-unknown-elf-gcc --cflags="-O2 -ffunction-sections -march=rv32g_zca" --ldflags="-O2 -W -march=rv32g_zca -Lm" --cc-output-pattern="-c" --user-libs="$HOME/zc-test/riscv-gnu-toolchain/opt-riscv-rv32-zca/riscv32-unknown-elf/lib/libm.a"
  
  The methods for other sub-extensions are the same as this one. You only need to modify "-march ", "-cc " and "-user-libs ".

4.run the benchmark_size.py to get the code size
  
  The results are as follows.
  ![image](https://user-images.githubusercontent.com/94943299/181216532-4123996e-213a-41f6-b308-47c232fbdef5.png)
