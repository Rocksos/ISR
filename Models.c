struct Type_item
{
	char DateStart[15];
	char AirPortNameStart[15];
	char AirPortNameFinish[15];
	char DateFinish[15];
	char Mark[30];
	struct Type_item *next;
};
struct Type_head
{
	struct Type_item *first;
	int count;
};