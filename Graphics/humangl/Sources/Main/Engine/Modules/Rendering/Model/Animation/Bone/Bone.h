#include <vector>
#include <Assimp.h>

#include "KeyPosition.h"
#include "KeyRotation.h"
#include "KeyScale.h"
#include "Matrix4x4.h"

namespace Engine
{
	class Bone;
}

class Engine::Bone final
{
public :

	Bone(const std::string &name, const aiNodeAnim* aiNodeAnim);

	Matrix4x4 getLocalTransform();
	std::string getBoneName() const;

	void update(float time);

private :

	std::vector<KeyPosition> _positions;
	std::vector<KeyRotation> _rotations;
	std::vector<KeyScale> _scales;

	Matrix4x4 _localTransform;
	std::string _name;

	int getPositionIndex(float animationTime);
	int getRotationIndex(float animationTime);
	int getScaleIndex(float animationTime);

	float getScaleFactor(float lastTimeStamp, float nextTimeStamp, float animationTime);

	Matrix4x4 interpolatePosition(float animationTime);
	Matrix4x4 interpolateRotation(float animationTime);
	Matrix4x4 interpolateScale(float animationTime);
};