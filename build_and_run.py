import os
import subprocess
from pathlib import Path
from colorama import Fore, Style

def run_test_exe():
    print(Fore.BLUE + 'execute test_agilerobot.exe\n' + Style.RESET_ALL)
    exe_path = 'D:/agilerobot/build/test_agilerobot.exe'
    if os.path.isfile(exe_path):
        result = subprocess.run([exe_path], capture_output=True, text=True)
        print(result.stdout)
    else:
        print(f"File not found: {exe_path}")    

def generate_coverage_report():
    try:
        #run gcovr command
        result = subprocess.run(
            ['py', '-m', 'gcovr', '-r', '..', '--html', '--html-details', '-o', 'coverage.html'],
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
    if not os.path.exists('build'):
        os.makedirs('build')
    else:
        print(Fore.GREEN + '!build path exist!\n' + Style.RESET_ALL)

# navigate to build dir
os.chdir('build')
Path.cwd()

# run cmake config
print(Fore.BLUE + 'run_command: cmake...\n' + Style.RESET_ALL)
run_command('cmake ..')

# build the project
print(Fore.BLUE + 'run_command: cmake --build .\n' + Style.RESET_ALL)
run_command('cmake --build .')

#run test
run_test_exe()

#generate coverage report
generate_coverage_report()


if __name__ == '__main__':
    main()