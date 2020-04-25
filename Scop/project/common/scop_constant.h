#ifndef SCOP_CONSTANT_H
# define SCOP_CONSTANT_H

# define SCOP_AXIS_X				vector3_pack(1, 0, 0)
# define SCOP_AXIS_Y				vector3_pack(0, 1, 0)
# define SCOP_AXIS_Z				vector3_pack(0, 0, 1)

# define SCOP_MODEL_COMMENT			"# "
# define SCOP_MODEL_EMPTY			" "
# define SCOP_MODEL_VERTEX			"v "
# define SCOP_MODEL_TEXTURE			"vt "
# define SCOP_MODEL_NORMAL			"vn "
# define SCOP_MODEL_FACE			"f "
# define SCOP_MODEL_LIBRARY			"mtllib "
# define SCOP_MODEL_MATERIAL		"usemtl "

# define SCOP_MATERIAL_NEW			"newmtl "
# define SCOP_MATERIAL_TEXTURE		"map_Kd "
# define SCOP_MATERIAL_AMBIENT		"Ka "
# define SCOP_MATERIAL_DIFFUSE		"Kd "
# define SCOP_MATERIAL_SPECULAR		"Ks "
# define SCOP_MATERIAL_EXPONENT		"Ns "
# define SCOP_MATERIAL_TRANSPARENT	"Tr "
# define SCOP_MATERIAL_DISSOLVE		"d "

#define SCOP_MOD_MATERIAL			0
#define SCOP_MOD_RANDOM				1
#define SCOP_MOD_TEXTURE			2

#endif
