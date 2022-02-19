#!/bin/bash

########################################################################################################################
# Constants
########################################################################################################################

REDIRECT_OUTPUT=1

RESET="\033[0m"
RED="\033[31m"
GREEN="\033[32m"

LIBRARIES="sources/external"

########################################################################################################################
# Common
########################################################################################################################

function raise_error
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

function write_new_line
{
	echo ""
}

function enter_folder
{
	cd "$1" > /dev/null 2>&1 || raise_error "Can't enter folder $1" "Can't download from URL ${URL}"
}

function log_start
{
	write "Installing $1..."
}

function log_finish
{
	write "Successfully installed ${GREEN}$1${RESET}!"
}

########################################################################################################################
# Web
########################################################################################################################

function download_from_git
{
	evaluate "git clone --recursive $1 $2"

	rm -rf "$2/.git"
	rm -f "$2/.gitignore"
}

########################################################################################################################
# Libraries
########################################################################################################################

function enter_libraries_folder
{
	mkdir -p "$LIBRARIES"
	enter_folder "$LIBRARIES"
}

function reset_libraries_folder
{
	rm -rf "$LIBRARIES"
}

########################################################################################################################
# Libraries : GLFW
########################################################################################################################

function install_glfw
{
	glfw_name="GLFW"
	glfw_url="https://github.com/glfw/glfw.git"
	glfw_project="glfw"

	log_start "${glfw_name}"

	download_from_git "${glfw_url}" "${glfw_project}"

	log_finish "${glfw_name}"
	write_new_line
}

########################################################################################################################
# Libraries : GLAD
########################################################################################################################

function install_glad
{
	glad_name="GLAD"
	glad_url="https://github.com/Lyahasik/glad"
	glad_project="glad"

	write "Installing ${glad_name}..."

	download_from_git "${glad_url}" "${glad_project}"

	write "Successfully installed ${GREEN}${glad_name}${RESET}!"
	write_new_line
}

########################################################################################################################
# Libraries : YAML_CPP
########################################################################################################################

function install_yaml_cpp
{
	yaml_cpp_name="Yaml-Cpp"
	yaml_cpp_url="https://github.com/jbeder/yaml-cpp.git"
	yaml_cpp_project="yaml-cpp"

	log_start "${yaml_cpp_name}"

	download_from_git "${yaml_cpp_url}" "${yaml_cpp_project}"

	log_finish "${yaml_cpp_name}"
	write_new_line
}

########################################################################################################################
# Libraries : ASSIMP
########################################################################################################################

function install_assimp
{
	assimp_name="ASSIMP"
	assimp_url="https://github.com/assimp/assimp.git"
	assimp_project="assimp"

	log_start "${assimp_name}"

	download_from_git $assimp_url

	enter_folder "${assimp_project}"

	evaluate "cmake CMakeLists.txt"
	evaluate "make -j4"

	enter_folder ..

	log_finish "${assimp_name}"
	write_new_line
}

########################################################################################################################
# Libraries : STB
########################################################################################################################

function install_stb
{
	stb_name="STB"
	stb_url="https://github.com/nothings/stb.git"
	stb_project="stb"

	log_start "${stb_name}"

	download_from_git "${stb_url}" "${stb_project}"

	log_finish "${stb_name}"
	write_new_line
}

########################################################################################################################
# Libraries : GLM
########################################################################################################################

function install_glm
{
	glm_name="GLM"
	glm_url="https://github.com/g-truc/glm.git"
	glm_project="glm"

	log_start "$glm_name"

	download_from_git "$glm_url" "$glm_project"

	log_finish "$glm_name"
	write_new_line
}

########################################################################################################################
# FreeType2
########################################################################################################################

function install_free_type
{
	free_type_name="FreeType2"
	free_type_url="https://github.com/aseprite/freetype2.git"
	free_type_project="freetype2"

	log_start "$free_type_name"

	download_from_git "$free_type_url" "$free_type_project"

	log_finish "$free_type_name"
}


########################################################################################################################
# Main
########################################################################################################################

while [[ "$#" -gt 0 ]]; do
    case $1 in
        -v) REDIRECT_OUTPUT=0; shift ;;
        *) echo "Unknown parameter passed: $1"; exit 1 ;;
    esac
    shift
done

reset_libraries_folder
enter_libraries_folder

install_glfw
install_glad
install_yaml_cpp
install_stb
install_assimp
install_glm
install_free_type