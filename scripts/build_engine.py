"""Build script for the SpaceEngine project.

Cleans the build directory, configures CMake, and builds the project.
Raises:
    NotImplementedError: If run on an unsupported platform.
"""

import os
import sys

import subprocess
import argparse
import pathlib
import shutil


# Supported platforms
PLATFORM_WINDOWS = 'win32'

# Supported build modes
# BUILD_MODE_DEBUG = 'debug'
# BUILD_MODE_RELEASE = 'release'
# BUILD_MODES = [BUILD_MODE_DEBUG, BUILD_MODE_RELEASE]
# BUILD_MODE_DICT = {key: key.capitalize() for key in BUILD_MODES}

# Paths
PROJECT_ROOT = pathlib.Path(__file__).resolve().parent.parent
BUILD_DIR = PROJECT_ROOT / 'build'
ENGINE_DIR = PROJECT_ROOT / 'engine'

# Argument parsing
parser = argparse.ArgumentParser(description='Configures and builds the project')
parser.add_argument('-c', '--configure', action='store_true', help='Runs the configuration step.')
args = parser.parse_args()

os.chdir(PROJECT_ROOT)

# Clean build directory
if args.configure:
    if not BUILD_DIR.exists():
        os.mkdir(BUILD_DIR)

    for item in BUILD_DIR.iterdir():
        if item.is_dir():
            shutil.rmtree(item, ignore_errors=True)
        else:
            item.unlink()

if not BUILD_DIR.exists():
    print('Build directory not found. Please run with --configure to create it.')
    sys.exit(1)
    
# Configure and build project
os.chdir(BUILD_DIR)
if sys.platform == PLATFORM_WINDOWS:
    # Configuration step
    if args.configure:
        cmake_config_cmd = [
            'cmake', str(ENGINE_DIR),
            '-G', 'Visual Studio 17 2022',
            '-A', 'x64',
        ]

        print('> Running:', ' '.join(cmake_config_cmd))
        subprocess.run(cmake_config_cmd, check=True)

    # Building step
    cmake_build_cmd = [
        'cmake',
        '--build', '.',
    ]

    print('> Running:', ' '.join(cmake_build_cmd))
    subprocess.run(cmake_build_cmd, check=True)

    # Copy .pyd file to /game directory
    shutil.copy(BUILD_DIR / 'Debug' / 'engine_lib.pyd', PROJECT_ROOT / 'game' / 'engine' / 'engine_lib.pyd')

    # Generate .pyi stub files for engine_lib
    os.chdir(PROJECT_ROOT / 'game' / 'engine')
    stub_gen_cmd = [
        'pybind11-stubgen',
        'engine_lib',
        '-o', '.'
    ]

    print('> Running:', ' '.join(stub_gen_cmd))
    subprocess.run(stub_gen_cmd, check=True)

else:
    print(f'Not implemented build for platform: \"{sys.platform}\"')
    exit(1)
