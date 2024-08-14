"""
AUTHOR: Ajay Shimpi
initial cmd after clone from ./build/
cmake -G "MinGW Makefiles" ..
coverage cmd:
py -m gcovr --html --html-details -o coverage.html --config ../gcovr.cfg
"""

import os
import subprocess
from pathlib import Path
from colorama import Fore, Style

def remove_cmakecache():
    cache_file_path = 'CMakeCache.txt' # type: ignore
    if os.path.exists(cache_file_path):
        os.remove(cache_file_path)
        print(f"{cache_file_path} has been removed.")
    else:
        print(f"{cache_file_path} not found.")

def run_mingw_makefiles():
    try:
        result = subprocess.run(
            ['cmake', '-G', 'MinGW Makefiles', '..'],
            check=True,
            capture_output=True,
            text=True
        )
        print(Fore.GREEN + '!Generator updated successfully!\n' + Style.RESET_ALL)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(Fore.RED + "!An error occured while updating generator!" + Style.RESET_ALL)
        print(e.stderr)

def run_test_exe():
    print(Fore.BLUE + 'execute test_agilerobot.exe\n' + Style.RESET_ALL)
    exe_path = r'./test_agilerobot.exe'
    if os.path.isfile(exe_path):
        result = subprocess.run([exe_path], capture_output=True, text=True)
        print(result.stdout)
    else:
        print(f"File not found: {exe_path}")    

def generate_coverage_report():
    try:
        #run gcovr command
        # ['py', '-m', 'gcovr', '--html', '--html-details', '-o', 'coverage.html'],
        result = subprocess.run(
            ['py', '-m', 'gcovr', '-r', '..', '--html', '--html-details', '-o', 'coverage.html', '--config', '../gcovr.cfg'],
            check=True,
            capture_output=True,
            text=True
        )
        print(Fore.GREEN + '!Coverage report generated successfully!\n' + Style.RESET_ALL)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print(Fore.RED + "!An error occured while generating Coverage report!" + Style.RESET_ALL)
        print(e.stderr)

def run_command(command):
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    if result.returncode !=0:
        print(f"Error: {result.stderr}")
    else:
        print(result.stdout)

def main():
    #create build directory
    print("\nCurrent working directory:", os.getcwd())
    if not os.path.exists('build'):
        os.makedirs('build')
    else:
        print(Fore.GREEN + '!build path exist!\n' + Style.RESET_ALL)

    # navigate to build dir
    print("\nCurrent working directory:", os.getcwd())
    os.chdir('build')

    # remove cmake cache
    print("\nCurrent working directory:", os.getcwd())
    remove_cmakecache()

    # update Generator
    print("\nCurrent working directory:", os.getcwd())
    run_mingw_makefiles()

    # run cmake config
    print("\nCurrent working directory:", os.getcwd())
    print(Fore.BLUE + 'run_command: cmake...\n' + Style.RESET_ALL)
    run_command('cmake ..')

    # build the project
    print("\nCurrent working directory:", os.getcwd())
    print(Fore.BLUE + 'run_command: cmake --build .\n' + Style.RESET_ALL)
    run_command('cmake --build .')

    #run test
    print("\nCurrent working directory:", os.getcwd())
    run_test_exe()

    #generate coverage report
    print("\nCurrent working directory:", os.getcwd())
    generate_coverage_report()


if __name__ == '__main__':
    main()

"""
# option: Custom target to run tests and generate coverage report
add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E env GCOV_PREFIX=${CMAKE_BINARY_DIR} GCOV_PREFIX_STRIP=1 ${CMAKE_CTEST_COMMAND} --output-on-failure
    COMMAND gcovr --html --html-details -o coverage.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
"""