//
// Created by Sanqian on 16/7/26.
//

#include <fstream>
#include <iostream>
#include "SiftFileLoader.h"
#include <stdlib.h>
#include <stdio.h>

void SiftFileLoader::loadFile(std::string fileName, std::vector<float> &keyPointBuffer, std::vector<float> &descriptionBuffer,int &descp_per_point) {
    std::ifstream file(fileName);

    if(file.is_open())
    {
        int featureNumber = 0;
        int siftFileType = 0;
        int linenumber = 0;
        while (file.good())
        {
            std::string line;
            std::getline(file,line);


            int numFloat = 0;
            float floats[20] = {0.0f};

            int startPos = 0;
            int floatEndPos = 0;
            int floatindex = 0;
            do{
                floatEndPos = line.find(' ',startPos);

                if(floatEndPos!=std::string::npos)
                {
                    floats[floatindex] = atof((line.substr(startPos,floatEndPos-1).c_str()));
                    startPos = floatEndPos+1;
                    floatindex++;
                }
            }while(floatEndPos!=std::string::npos);

            floats[floatindex] = std::atoi((line.substr(startPos,line.length()-1).c_str()));
            if(floatindex == 1 && linenumber == 0)
            {
                //First line
                featureNumber = floats[0];
                siftFileType = floats[1];
                descp_per_point = siftFileType;
                //First line?
            }
            else if(floatindex == 3)
            {
                //Point line
                float x = floats[0];
                float y = floats[1];
                float scale = floats[2];
                float rotation_order = floats[3];
                keyPointBuffer.push_back(x);
                keyPointBuffer.push_back(y);
                keyPointBuffer.push_back(scale);
                keyPointBuffer.push_back(rotation_order);

            }
            else
            {
                for(int i = 0;i<floatindex;i++)
                {
                    float value = floats[i];
                    descriptionBuffer.push_back(value);
                }
            }
//            std::cout<<line<<std::endl;

            linenumber++;
        }
    }

}