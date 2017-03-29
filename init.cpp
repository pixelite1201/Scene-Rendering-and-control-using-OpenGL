void init()
{
	
	//box_id=glGenLists(1);
	box2_id=glGenLists(1);
	table_id=glGenLists(1);
	chair_id=glGenLists(1);
	room_id = glGenLists(1);
	cupboard_id = glGenLists(1);
	lamp_id=glGenLists(1);
	//struct_box();
	struct_box2();
	struct_table();
	struct_chair();
	struct_room();
	struct_cupboard();
	struct_lamp();
	

	head_id=glGenLists(1);
	neck_id=glGenLists(1);
	torso_id=glGenLists(1);
	left_upper_arm_id=glGenLists(1);
	left_lower_arm_id=glGenLists(1);
	left_hand_id=glGenLists(1);
	right_upper_arm_id=glGenLists(1);
	right_lower_arm_id=glGenLists(1);
	right_hand_id=glGenLists(1);
	hip_id=glGenLists(1);
	left_upper_leg_id=glGenLists(1);
	left_lower_leg_id=glGenLists(1);
	left_feet_id=glGenLists(1);
	right_upper_leg_id=glGenLists(1);
	right_lower_leg_id=glGenLists(1);
	right_feet_id=glGenLists(1);
	box_id=glGenLists(1);
	
	struct_box();
	struct_hip();
	struct_head();
	struct_neck();
	struct_torso();
	struct_left_upper_leg();
	struct_left_lower_leg();
	struct_left_feet();
	struct_right_upper_leg();
	struct_right_lower_leg();
	struct_right_feet();
	struct_left_upper_arm();
	struct_right_upper_arm();
	struct_left_lower_arm();
	struct_right_lower_arm();
	struct_left_hand();
	struct_right_hand();
	

}

