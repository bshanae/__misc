#!/bin/bash

########################################################################################################################
# Constants
########################################################################################################################

REDIRECT_OUTPUT=1

RESET="\033[0m"
RED="\033[31m"
GREEN="\033[32m"

LIBRARIES="Sources/Libraries"

########################################################################################################################
# Common
########################################################################################################################

function raiseError
{
	echo -e "${RED}Error : $1${RESET}"
	exit
}

function evaluate
{
	command="$1"
	options=""

	if ((REDIRECT_OUTPUT)); then
		options="> /dev/null 2>&1"
	fi

	eval "${command}" "${options}"
}

########################################################################################################################
# IO
########################################################################################################################

function write
{
	echo -e "$1"
}

function writeNewLine
{
	echo ""
}

function enterFolder
{
	cd "$1" > /dev/null 2>&1 || raiseError "Can't enter folder $1" "Can't download from URL ${URL}"
}

function logStart
{
	write "Installing $1..."
}

function logFinish
{
	write "Successfully installed ${GREEN}$1${RESET}!"
}

########################################################################################################################
# Libraries
########################################################################################################################

function enterLibrariesFolder
{
	mkdir -p "$LIBRARIES"
	enterFolder "$LIBRARIES"
}

function resetLibrariesFolder
{
	rm -rf "$LIBRARIES"
}

########################################################################################################################
# GIT
########################################################################################################################

function downloadRepo
{
	evaluate "git clone --recursive $1 $2"

	rm -rf "$2/.git"
	rm -f "$2/.gitignore"
}

########################################################################################################################
# GLFW
########################################################################################################################

function installGlfw
{
	glfwName="GLFW"
	glfwUrl="https://github.com/glfw/glfw.git"
	glfwProject="glfw"

	logStart "${glfwName}"

	downloadRepo "${glfwUrl}" "${glfwProject}"

	logFinish "${glfwName}"
	writeNewLine
}

########################################################################################################################
# GLAD
########################################################################################################################

function installGlad
{
	gladName="GLAD"
	gladUrl="https://github.com/Lyahasik/glad"
	gladProject="glad"

	write "Installing ${gladName}..."

	downloadRepo "${gladUrl}" "${gladProject}"

	write "Successfully installed ${GREEN}${gladName}${RESET}!"
	writeNewLine
}

########################################################################################################################
# YAML_CPP
########################################################################################################################

function installYamlCpp
{
	yamlCppName="yaml-cpp"
	yamlCppUrl="https://github.com/jbeder/yaml-cpp.git"
	yamlCppProject="yaml-cpp"

	logStart "${yamlCppName}"

	downloadRepo "${yamlCppUrl}" "${yamlCppProject}"

	logFinish "${yamlCppName}"
	writeNewLine
}

########################################################################################################################
# Assimp
########################################################################################################################

function installAssimp
{
	assimpName="assimp"
	assimpUrl="https://github.com/assimp/assimp.git"
	assimpProject="assimp"

	logStart "${assimpName}"

	evaluate "git clone --recursive ${assimpUrl} ${assimpProject}"

	enterFolder  "${assimpProject}"

	evaluate "git checkout 8840449226888801f64394fe8abe7f1b0372d499"
	rm -rf ".git"
	rm -f ".gitignore"

	evaluate "cmake CMakeLists.txt"
	evaluate "make -j4"

	enterFolder ..

	logFinish "${assimpName}"
	writeNewLine
}

########################################################################################################################
# Stb
########################################################################################################################

function installStb
{
	stbName="stb"
	stbUrl="https://github.com/nothings/stb.git"
	stbProject="stb"

	logStart "${stbName}"

	downloadRepo "${stbUrl}" "${stbProject}"

	logFinish "${stbName}"
	writeNewLine
}

########################################################################################################################
# Main
########################################################################################################################

resetLibrariesFolder
enterLibrariesFolder

installGlfw
installGlad
installYamlCpp
installStb
installAssimp