unsigned clock_simulate(unsigned pages[], unsigned pages_len, unsigned table_len);
void print_frame(int * frames, int * r, int len);
void clock(unsigned * pg, unsigned pages_len, int page_file_len);
int find(int *hit_p, int* frames, int page, const int frame_len);
