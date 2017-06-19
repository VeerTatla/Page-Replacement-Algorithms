
void page_replacement_sim();
unsigned read_page_file(unsigned (*pages_ptr)[]);
int exists(int frame_size,int page_frames[],int page_num);
void print_frame(int * frames, int * r, int len);
void display(int page_frames[],int frame_size);
