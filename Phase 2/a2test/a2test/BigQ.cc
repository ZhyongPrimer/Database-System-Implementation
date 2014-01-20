#include "BigQ.h"

BigQ :: BigQ (Pipe &in, Pipe &out, OrderMaker &sortorder, int runlen) {
	
	this->run_no = 0;
	
	buffer = new Page[runlen];
	
 	
	args_phase1.input = &in;
	args_phase1.sort_order = &sortorder;
	args_phase1.run_length = &runlen;
	
	pthread_create (&worker, NULL, TPMMS_phase1 , (void *)&args_phase1);
	
	// read data from in pipe sort them into runlen pages
	
    // construct priority queue over sorted runs and dump sorted data 
 	// into the out pipe

    // finally shut down the out pipe
	out.ShutDown ();
}

BigQ::void* TPMMS_Phase1(void* arg){
	/*
	Pipe *input;
		OrderMaker *sort_order;
		int run_length;
		Record *temporary = &temp;
		Page *buf = buffer;
		*/
	int page_Index = 1;
	struct args_phase1_struct *args = arg;
	args->num_runs = 0;//goes from 0 to n
	
	//Create and open new file 'file.run_no'
	args->(*run_buffer)[++num_runs] = new File();//file for run1
	char *actual_path;
	sprintf(actual_path,"%s.%d",file_path,num_runs);
	args->(*run_buffer)[num_runs]->Open(0,actual_path);
	
	//***check resets of indexes
	while(args->input->remove(args->temporary)!=0){ // till input pipe is empty
	
		
		
		
		//append record temporary to page at pageindex
		if(args->(*buf)[page_Index]->append(args->temporary) == 0){//if page is full
			
			//add page to file buffer at page_index
			args->(*run_buffer)[num_runs]->AddPage(args->(*buf)[page_Index],page_Index);//getlength doesnt work use page index
			
				
			if(++page_Index>args->run_length){//increment if run length is exceeded 
			
				//Sort runs
				
				
				
				

				
				args->(*run_buffer)[++num_runs] = new File();  //create new run file
				char *actual_path;
				sprintf(actual_path,"%s.%d",file_path,num_runs);//set path as "file_path.num_run"
				args->(*run_buffer)[num_runs]->open(0,args->file_path);//??concatenate run no
				
				
				for(i=0;i<args->run_length;i++)
					args->(*buf)[i]->EmptyItOut();
				
				page_Index=1;
				args->(*buf)[page_Index]->append(args->temporary);
				//code for writing out the run and empting the page buffer
				//USE FILE OBJECT??
			} // page index out of bound

			page_Index = 1;//reset page index
			
		}
		
		//  if page is full, increment page index
		//  if page index is out of bound, sort() page[]
		// write out as page[] run as binary
		// empty put page[]
		
	}
	 
}

BigQ::~BigQ () {
	delete buffer;
	//delete thread
}
