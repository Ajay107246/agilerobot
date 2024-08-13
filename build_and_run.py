import os
import subprocess
from pathlib import Path

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
        print('build path exist\n')

#navigate to build dir
os.chdir('build')
Path.cwd()

#run cmake config
print('run_command: cmake...\n')
run_command('cmake ..')

#build the project
print('run_command: cmake --build .\n')
run_command('cmake --build .')

#run test
print('execute test_agilerobot.exe\n')
exe_path = 'D:/agilerobot/build/test_agilerobot.exe'
if os.path.isfile(exe_path):
    result = subprocess.run([exe_path], capture_output=True, text=True)
    print(result.stdout)
else:
    print(f"File not found: {exe_path}")


if __name__ == '__main__':
    main()