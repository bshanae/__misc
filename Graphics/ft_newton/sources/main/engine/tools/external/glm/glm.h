#pragma once

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/epsilon.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/norm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

#include "Forward.h"

namespace engine
{
	using glm::radians;
	using glm::clamp;

	using glm::distance;
	using glm::cross;
	using glm::dot;

	using glm::quat_identity;
	using glm::angleAxis;
	using glm::mat4_cast;
	using glm::conjugate;

	using glm::eulerAngleXYX;
	using glm::scale;
	using glm::translate;
	using glm::perspective;
	using glm::ortho;
	using glm::lookAt;
}