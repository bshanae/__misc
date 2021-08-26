#include "Bone.h"

#include "Converter.h"

using namespace Engine;

Bone::Bone(const std::string &name, const aiNodeAnim* aiNodeAnim) : _name(name)
{
	_localTransform = Matrix4x4::makeIdentity();

	for (int positionIndex = 0; positionIndex < aiNodeAnim->mNumPositionKeys; ++positionIndex)
	{
		const auto aiPosition = aiNodeAnim->mPositionKeys[positionIndex].mValue;
		const auto timeStamp = (float)aiNodeAnim->mPositionKeys[positionIndex].mTime;

		_positions.push_back({Converter::convert(aiPosition), timeStamp});
	}

	for (int rotationIndex = 0; rotationIndex < aiNodeAnim->mNumRotationKeys; ++rotationIndex)
	{
		const auto aiOrientation = aiNodeAnim->mRotationKeys[rotationIndex].mValue;
		const auto timeStamp = (float)aiNodeAnim->mRotationKeys[rotationIndex].mTime;

		_rotations.push_back({Converter::convert(aiOrientation), timeStamp});
	}

	for (int keyIndex = 0; keyIndex < aiNodeAnim->mNumScalingKeys; ++keyIndex)
	{
		const auto scale = aiNodeAnim->mScalingKeys[keyIndex].mValue;
		const auto timeStamp = (float)aiNodeAnim->mScalingKeys[keyIndex].mTime;

		_scales.push_back({Converter::convert(scale), timeStamp});
	}
}

Matrix4x4 Bone::getLocalTransform()
{
	return _localTransform;
}

std::string Bone::getBoneName() const
{
	return _name;
}

int Bone::getPositionIndex(float time)
{
	int index = -1;

	while (++index < _positions.size() - 1)
	{
		if (time <= _positions[index + 1].timeStamp)
			return index;
	}

	return index + 1;
}

int Bone::getRotationIndex(float time)
{
	int index = -1;

	while (++index < _rotations.size() - 1)
	{
		if (time < _rotations[index + 1].timeStamp)
			return index;
	}

	return index + 1;
}

int Bone::getScaleIndex(float time)
{
	int index = -1;

	while (++index < _scales.size() - 1)
	{
		if (time < _scales[index + 1].timeStamp)
			return index;
	}

	return index + 1;
}

void Bone::update(float time)
{
	const auto translation = interpolatePosition(time);
	const auto rotation = interpolateRotation(time);
	const auto scale = interpolateScale(time);

	_localTransform = translation * rotation * scale;
}

float Bone::getScaleFactor(float lastTimeStamp, float nextTimeStamp, float time)
{
	float midWayLength = time - lastTimeStamp;
	float framesDiff = nextTimeStamp - lastTimeStamp;
	float scaleFactor = midWayLength / framesDiff;

	return scaleFactor;
}

Matrix4x4 Bone::interpolatePosition(float time)
{
	if (_positions.size() == 1)
		return Matrix4x4::makeTranslation(_positions[0].position);

	auto currentIndex = getPositionIndex(time);
	auto nextIndex = currentIndex + 1;

	float scaleFactor = getScaleFactor(
		_positions[currentIndex].timeStamp,
		_positions[nextIndex].timeStamp,
		time);

	auto finalPosition = Vector3::mix(
		_positions[currentIndex].position,
		_positions[nextIndex].position,
		scaleFactor);

	return Matrix4x4::makeTranslation(finalPosition);
}

Matrix4x4 Bone::interpolateRotation(float time)
{
	if (_rotations.size() == 1)
		return Matrix4x4::makeRotation(Quaternion::normalize(_rotations[0].orientation));

	auto currentIndex = getRotationIndex(time);
	auto nextIndex = currentIndex + 1;

	auto scaleFactor = getScaleFactor(
		_rotations[currentIndex].timeStamp,
		_rotations[nextIndex].timeStamp,
		time);

	auto finalRotation = Quaternion::slerp(
		_rotations[currentIndex].orientation,
		_rotations[nextIndex].orientation,
		scaleFactor);

	finalRotation = Quaternion::normalize(finalRotation);
	return Matrix4x4::makeRotation(finalRotation);
}

Matrix4x4 Bone::interpolateScale(float time)
{
	if (_scales.size() == 1)
		return Matrix4x4::makeScale(_scales[0].scale);

	auto currentIndex = getScaleIndex(time);
	auto nextIndex = currentIndex + 1;

	auto scaleFactor = getScaleFactor(
		_scales[currentIndex].timeStamp,
		_scales[nextIndex].timeStamp,
		time);

	auto finalScale = Vector3::mix(
		_scales[currentIndex].scale,
		_scales[nextIndex].scale,
		scaleFactor);

	return Matrix4x4::makeScale(finalScale);
}