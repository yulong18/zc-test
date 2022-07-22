git clone https://github.com/pz9115/riscv-gnu-toolchain.git
cd riscv-gnu-toolchain
git submodule update --init
cd riscv-gcc
git remote add corev https://github.com/plctlab/corev-gcc.git
git fetch corev
git checkout corev/development

cd ../riscv-binutils

git remote add corev https://github.com/plctlab/corev-binutils-gdb.git
git fetch corev 
git checkout corev/development 

cd ../qemu
git remote add plctlab https://github.com/plctlab/plct-qemu.git
git fetch plctlab
git checkout plctlab/plct-zce-0.70.0

cd ..

./configure --prefix="$PWD/opt-riscv-rv32-zcmt" --with-arch=rv32g_zca_zcmt --with-abi=ilp32 --with-multilib-generator="rv32g_zca_zcmt-ilp32--"
make report-gcc-newlib -j $(nproc) &&
make report-binutils-newlib -j $(nproc)
