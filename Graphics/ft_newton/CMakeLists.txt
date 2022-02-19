cmake_minimum_required(VERSION 3.19)
project(ft_newtone)

set(CMAKE_CXX_STANDARD 17)

include_directories(
	# libraries
	sources/external/glad/include
	sources/external/stb
	sources/external/glm
	sources/external/freetype2/include

	# main
	sources/main)

set(EXTERNAL_SOURCES
	sources/external/glad/src/glad.c)

set(ENGINE_SOURCES
	# core
	sources/main/engine/core/settings/Settings.cpp
	sources/main/engine/core/processor/Processor.cpp
	sources/main/engine/core/processor/Processor-Environment.cpp
	sources/main/engine/core/processor/Processor-Modules.cpp
	sources/main/engine/core/processor/Processor-Scene.cpp
	sources/main/engine/core/scene/Scene.cpp
	sources/main/engine/core/scene/object/prototype/Prototype.cpp
	sources/main/engine/core/scene/object/prototype/prototypeStorage/PrototypeStorage.cpp
	sources/main/engine/core/scene/object/Object.cpp
	sources/main/engine/core/scene/object/serialization/Serialization.cpp
	sources/main/engine/core/scene/object/component/Component.cpp
	sources/main/engine/core/scene/serialization/Serialization.cpp

	# environment
	sources/main/engine/environment/environment/Environment.cpp
	sources/main/engine/environment/window/Window.cpp
	sources/main/engine/environment/input/Input.cpp
	sources/main/engine/environment/shader/Shader.cpp
	sources/main/engine/environment/shader/subShader/SubShader.cpp

	# tools
	sources/main/engine/tools/color/Color.cpp

	# modules : base
	sources/main/engine/modules/base/module/Module.cpp
	sources/main/engine/modules/base/components/transformation/Transformation.cpp

	# modules : rendering
	sources/main/engine/modules/rendering/module/Module.cpp
	sources/main/engine/modules/rendering/settings/Settings.cpp
	sources/main/engine/modules/rendering/components/camera/Camera.cpp
	sources/main/engine/modules/rendering/components/camera/freeCamera/FreeCamera.cpp
	sources/main/engine/modules/rendering/components/model/Model.cpp
	sources/main/engine/modules/rendering/components/model/mesh/Mesh.cpp
	sources/main/engine/modules/rendering/components/model/modelParser/ModelParser.cpp
	sources/main/engine/modules/rendering/components/model/modelStorage/ModelStorage.cpp
	sources/main/engine/modules/rendering/components/model/modelRenderer/ModelRenderer.cpp
	sources/main/engine/modules/rendering/components/light/ambientLight/AmbientLight.cpp
	sources/main/engine/modules/rendering/components/light/pointLight/PointLight.cpp
	sources/main/engine/modules/rendering/tools/cameraFinder/CameraFinder.cpp
	sources/main/engine/modules/rendering/tools/shaders/litShader/LitShader.cpp
	sources/main/engine/modules/rendering/tools/shaders/unlitShader/UnlitShader.cpp

	# modules : physics
	sources/main/engine/modules/physics/module/Module.cpp
	sources/main/engine/modules/physics/settings/Settings.cpp
	sources/main/engine/modules/physics/algorithm/primitives/plane/Plane.cpp
	sources/main/engine/modules/physics/algorithm/primitives/box/Box.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector+SphereSphere.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector+SpherePlane.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector+SphereBox.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector+PlaneSphere.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector+PlaneBox.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector+BoxSphere.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector+BoxPlane.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionDetector/CollisionDetector+BoxBox.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionResolver/CollisionResolver.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionResolver/CollisionResolver+Preparation.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionResolver/CollisionResolver+InterpenetrationResolution.cpp
	sources/main/engine/modules/physics/algorithm/collision/collisionResolver/CollisionResolver+VelocityResolution.cpp
	sources/main/engine/modules/physics/components/collider/Collider.cpp
	sources/main/engine/modules/physics/components/collider/planeCollider/PlaneCollider.cpp
	sources/main/engine/modules/physics/components/collider/sphereCollider/SphereCollider.cpp
	sources/main/engine/modules/physics/components/collider/boxCollider/BoxCollider.cpp
	sources/main/engine/modules/physics/components/rigidBody/RigidBody.cpp

	# modules : ui
	sources/main/engine/modules/ui/module/Module.cpp
	sources/main/engine/modules/ui/settings/Settings.cpp
	sources/main/engine/modules/ui/tools/font/Font.cpp
	sources/main/engine/modules/ui/tools/font/symbol/Symbol.cpp
	sources/main/engine/modules/ui/tools/font/fontLibrary/FontLibrary.cpp
	sources/main/engine/modules/ui/components/text/Text.cpp
	sources/main/engine/modules/ui/components/text/textRenderer/TextRenderer.cpp
	sources/main/engine/modules/ui/components/text/textShader/TextShader.cpp
	sources/main/engine/modules/ui/components/button/Button.cpp
	sources/main/engine/modules/ui/components/switch/Switch.cpp
	sources/main/engine/modules/ui/components/background/Background.cpp
	sources/main/engine/modules/ui/components/background/backgroundRenderer/BackgroundRenderer.cpp

	# game
	sources/main/game/scene/menu/Menu.cpp
	sources/main/game/scene/menu/page/Page.cpp
	sources/main/game/scene/menu/pageWithSelector/PageWithSelector.cpp
	sources/main/game/scene/menu/pageSwitcher/PageSwitcher.cpp
	sources/main/game/scene/buttons/sceneLauncher/SceneLauncher.cpp
	sources/main/game/scene/buttons/sceneResetter/SceneResetter.cpp
	sources/main/game/scene/buttons/sceneCloser/SceneCloser.cpp)

if (DEV)
	set(GAME_SOURCES
		sources/main/test/scene/components/instruments/manipulator/Manipulator.cpp
		sources/main/test/scene/components/instruments/manipulator/manipulatorController/ManipulatorController.cpp
		sources/main/test/scene/components/instruments/shooter/Shooter.cpp
		sources/main/test/scene/components/instruments/shooter/shooterController/ShooterController.cpp
		sources/main/test/scene/components/instruments/colliderVisualiser/ColliderVisualiser.cpp
		sources/main/test/scene/components/instruments/colliderVisualiser/colliderVisualiserController/ColliderVisualiserController.cpp
		sources/main/test/scene/components/instruments/collisionVisualiser/CollisionVisualiser.cpp
		sources/main/test/scene/components/instruments/collisionVisualiser/collisionVisualiserController/CollisionVisualiserController.cpp
		sources/main/test/scene/components/statistics/fpsDisplayer/FpsDisplayer.cpp
		sources/main/test/scene/components/statistics/drawCallCountDisplayer/DrawCallCountDisplayer.cpp
		sources/main/test/scene/components/statistics/colliderCountDisplayer/ColliderCountDisplayer.cpp
		sources/main/test/scene/components/renderers/debugModelRenderer/DebugModelRenderer.cpp
		sources/main/test/scene/tools/sceneIterator/SceneIterator.cpp
		sources/main/test/launcher/Launcher.cpp
		sources/main/test/launcher/Main.cpp)
elseif (PROD)
	set(GAME_SOURCES
		sources/main/game/launcher/Launcher.cpp
		sources/main/game/launcher/Main.cpp)
endif()

add_executable(ft_newtone
	${EXTERNAL_SOURCES}
	${ENGINE_SOURCES}
	${GAME_SOURCES})

if (DEV)
	add_compile_definitions(DEV)
endif()

set(CMAKE_MESSAGE_LOG_LEVEL "WARNING")

add_subdirectory(sources/external/glfw)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
target_link_libraries(ft_newtone SYSTEM glfw)

add_subdirectory(sources/external/yaml-cpp)
target_link_libraries(ft_newtone SYSTEM yaml-cpp)

add_subdirectory(sources/external/assimp)
target_link_libraries(ft_newtone SYSTEM assimp)

add_subdirectory(sources/external/freetype2)
target_link_libraries(ft_newtone SYSTEM freetype)