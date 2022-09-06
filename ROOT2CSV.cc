//
// Created by Stephane Zsoldos on 6/27/22.
//

#include <fstream>
#include <iostream>

#include <wRATter/Wrapper.hh>

int main(int argc, char* argv[]){

  if(argc<3){
		std::cout << "./ROOT2CSV in.root out.csv\n";
		return EXIT_FAILURE;
  }

  std::ofstream fCSVOut(argv[2], std::ios::out);
  fCSVOut << "ievt,itrig,vtx_x,vtx_y,vtx_z,E,NHits,Q\n";
  wRAT w_rat(argv[1]);

	while(w_rat.GetNextEvent()){
		while(w_rat.GetNextTrigger()){
			fCSVOut << w_rat.GetIEvt()  << ","
							<< w_rat.GetITrig() << ","	
							<< w_rat.GetPosTrue(0).x() << ","	
							<< w_rat.GetPosTrue(0).y() << ","	
							<< w_rat.GetPosTrue(0).z() << ","	
							<< w_rat.GetETrue(0) << ","	
							<< w_rat.GetNHits() << ","	
							<< w_rat.GetQ()     << std::endl;
		}
	}

  fCSVOut.close();

  return EXIT_SUCCESS;
}
