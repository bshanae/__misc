cmake_minimum_required(VERSION 3.19)
project(humangl)

set(CMAKE_CXX_STANDARD 17)

include_directories(
	# Libraries
	Sources/Libraries/glad/include
	Sources/Libraries/stb

	# Engine : Core
	Sources/Main/Engine/Core/Processor
	Sources/Main/Engine/Core/Scene
	Sources/Main/Engine/Core/Scene/Object
	Sources/Main/Engine/Core/Scene/Object/Component
	Sources/Main/Engine/Core/Scene/Object/Component/ComponentManipulator
	Sources/Main/Engine/Core/Scene/SceneParser
	Sources/Main/Engine/Core/Scene/SceneParser/ObjectParser
	Sources/Main/Engine/Core/Scene/SceneParser/ComponentParser

	# Engine : Environment
	Sources/Main/Engine/Environment
	Sources/Main/Engine/Environment/Window
	Sources/Main/Engine/Environment/Input
	Sources/Main/Engine/Environment/Program
	Sources/Main/Engine/Environment/Program/Shader
	Sources/Main/Engine/Environment/Program/Uniform

	# Engine : Modules : Rendering
	Sources/Main/Engine/Modules/Rendering/Camera/DefaultCamera
	Sources/Main/Engine/Modules/Rendering/Model
	Sources/Main/Engine/Modules/Rendering/Model/Animator
	Sources/Main/Engine/Modules/Rendering/Model/Animation
	Sources/Main/Engine/Modules/Rendering/Model/Animation/Bone
	Sources/Main/Engine/Modules/Rendering/Model/Animation/Bone/BoneInfo
	Sources/Main/Engine/Modules/Rendering/Model/Animation/Bone/Keys
	Sources/Main/Engine/Modules/Rendering/Model/Animation/AssimpNodeInfo
	Sources/Main/Engine/Modules/Rendering/Model/Mesh
	Sources/Main/Engine/Modules/Rendering/Model/Mesh/Vertex
	Sources/Main/Engine/Modules/Rendering/Model/Material
	Sources/Main/Engine/Modules/Rendering/Model/Material/Texture
	Sources/Main/Engine/Modules/Rendering/Model/Transformable
	Sources/Main/Engine/Modules/Rendering/Renderer/DefaultProgram
	Sources/Main/Engine/Modules/Rendering/Renderer/DefaultRenderer
	Sources/Main/Engine/Modules/Rendering/Light/AmbientLight
	Sources/Main/Engine/Modules/Rendering/Light/PointLight

	# Engine : Tools
	Sources/Main/Engine/Tools/External
	Sources/Main/Engine/Tools/Exception
	Sources/Main/Engine/Tools/Singleton
	Sources/Main/Engine/Tools/Color
	Sources/Main/Engine/Tools/Math/Converter
	Sources/Main/Engine/Tools/Math/Vector2
	Sources/Main/Engine/Tools/Math/Vector3
	Sources/Main/Engine/Tools/Math/Vector4
	Sources/Main/Engine/Tools/Math/Quaternion
	Sources/Main/Engine/Tools/Math/Matrix4x4
	Sources/Main/Engine/Tools/Math/MathUtilities
	Sources/Main/Engine/Tools/Parsing/Configuration
	Sources/Main/Engine/Tools/VectorTools

	# Game
	Sources/Main/Game/Scene/MeshSelector
	Sources/Main/Game/Scene/MeshManipulator
	Sources/Main/Game/Scene/SceneCloser
	Sources/Main/Game/Launcher
)

add_subdirectory(Sources/Libraries/glfw)
add_subdirectory(Sources/Libraries/yaml-cpp)
add_subdirectory(Sources/Libraries/assimp)

add_executable(humangl
	# Libraries
	Sources/Libraries/glad/src/glad.c

	# Engine : Core
	Sources/Main/Engine/Core/Processor/Processor.cpp
	Sources/Main/Engine/Core/Processor/Processor+Environment.cpp
	Sources/Main/Engine/Core/Processor/Processor+Scene.cpp
	Sources/Main/Engine/Core/Scene/Scene.cpp
	Sources/Main/Engine/Core/Scene/Object/Object.cpp
	Sources/Main/Engine/Core/Scene/Object/Component/Component.cpp
	Sources/Main/Engine/Core/Scene/Object/Component/ComponentManipulator/ComponentManipulator.cpp
	Sources/Main/Engine/Core/Scene/SceneParser/SceneParser.cpp
	Sources/Main/Engine/Core/Scene/SceneParser/ObjectParser/ObjectParser.cpp

	# Engine : Environment
	Sources/Main/Engine/Environment/Environment.cpp
	Sources/Main/Engine/Environment/Window/Window.cpp
	Sources/Main/Engine/Environment/Input/Input.cpp
	Sources/Main/Engine/Environment/Program/Program.cpp
	Sources/Main/Engine/Environment/Program/Shader/Shader.cpp

	# Engine : Modules : Rendering
	Sources/Main/Engine/Modules/Rendering/Camera/DefaultCamera/DefaultCamera.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Model.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Animator/Animator.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Animation/Animation.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Animation/Bone/Bone.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Mesh/Mesh.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Mesh/Vertex/Vertex.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Material/Material.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Material/Texture/Texture.cpp
	Sources/Main/Engine/Modules/Rendering/Model/Transformable/Transformable.cpp
	Sources/Main/Engine/Modules/Rendering/Renderer/DefaultProgram/DefaultProgram.cpp
	Sources/Main/Engine/Modules/Rendering/Renderer/DefaultRenderer/DefaultRenderer.cpp
	Sources/Main/Engine/Modules/Rendering/Light/AmbientLight/AmbientLight.cpp
	Sources/Main/Engine/Modules/Rendering/Light/PointLight/PointLight.cpp

	# Engine : Tools
	Sources/Main/Engine/Tools/Color/Color.cpp
	Sources/Main/Engine/Tools/Math/Vector2/Vector2.cpp
	Sources/Main/Engine/Tools/Math/Vector3/Vector3.cpp
	Sources/Main/Engine/Tools/Math/Vector4/Vector4.cpp
	Sources/Main/Engine/Tools/Math/Quaternion/Quaternion.cpp
	Sources/Main/Engine/Tools/Math/Matrix4x4/Matrix4x4.cpp
	Sources/Main/Engine/Tools/Math/MathUtilities/MathUtilities.cpp
	Sources/Main/Engine/Tools/Parsing/Configuration/Configuration.cpp

	# Game
	Sources/Main/Game/Scene/MeshSelector/MeshSelector.cpp
	Sources/Main/Game/Scene/MeshManipulator/MeshManipulator.cpp
	Sources/Main/Game/Scene/SceneCloser/SceneCloser.cpp
	Sources/Main/Game/Launcher/Launcher.cpp
	Sources/Main/Game/Main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
target_link_libraries(humangl LINK_PUBLIC glfw)

target_link_libraries(humangl LINK_PUBLIC yaml-cpp)
target_include_directories(humangl PUBLIC Sources/Libraries/yaml-cpp/include)

target_link_libraries(humangl LINK_PUBLIC assimp)
target_include_directories(humangl PUBLIC Sources/Libraries/assimp/include)