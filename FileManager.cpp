#include "FileManager.h"

#include <iostream>

void FileManager::SaveHighScore(int data)
{
}

std::string FileManager::GetFilePath(FileData name)
{
    if (IsLoaded(name))
    return this->m_AssetFiles.at(name);
}

float FileManager::GetConfigFloat(FileData name)
{
    if (IsLoaded(name))
    return this->m_FileConfigFloats.at(name);
}

int FileManager::GetConfigInt(FileData name)
{
    if (IsLoaded(name))
    return this->m_FileConfigInts.at(name);
}


void FileManager::Load()
{
    std::ifstream file;
    std::string word;
    int intNumber;
    float floatNumber;
    int enumKey;
    file.open(kGameConfigFile);

    if (file.is_open())
    {
        for (size_t i = 3000; i < static_cast<size_t>(FileData::kSize) - 1; ++i)
        {
     
            file >> enumKey;
            if (enumKey < 3014)
            {
              
                if (enumKey == 3000)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                }
                else if (enumKey == 3001)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                
                }

                else if (enumKey == 3002)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
               
                }

                else if (enumKey == 3003)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
             
                }

                else if (enumKey == 3004)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
           
                }

                else if (enumKey == 3005)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                 
                }

                else if (enumKey == 3006)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                  
                }

                else if (enumKey == 3007)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                 
                }
                else if (enumKey == 3008)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                  
                }

                else  if (enumKey == 3009)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                  
                }

                else  if (enumKey == 3010)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                   
                }

                else if (enumKey == 3011)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                  
                }

                else if (enumKey == 3012)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                    
                }

                else if (enumKey == 3013)
                {
                    file >> word;
                    m_AssetFiles[static_cast<FileData>(enumKey)] = word;
                    
                }
          
                continue;
            }
            else if (enumKey > 3013 && enumKey < 3019)
            {
              if (enumKey == 3014)
                {
                    file >> intNumber;
                    m_FileConfigInts[static_cast<FileData>(enumKey)] = intNumber;
                 
                }

              else if (enumKey == 3015)
                {
                    file >> intNumber;
                    m_FileConfigInts[static_cast<FileData>(enumKey)] = intNumber;

                }

              else  if (enumKey == 3016)
                {
                    file >> intNumber;
                    m_FileConfigInts[static_cast<FileData>(enumKey)] = intNumber;
            
                }

              else if (enumKey == 3017)
                {
                    file >> intNumber;
                    m_FileConfigInts[static_cast<FileData>(enumKey)] = intNumber;
             
                }

              else if (enumKey == 3018)
                {
                    file >> intNumber;
                    m_FileConfigInts[static_cast<FileData>(enumKey)] = intNumber;
                
                }
         
                continue;
            }
          
            {
                if (enumKey == 3019)
                {
                    file >> floatNumber;
                    m_FileConfigFloats[static_cast<FileData>(enumKey)] = floatNumber;
            
                }

                else if (enumKey == 3020)
                {
                    file >> floatNumber;
                    m_FileConfigFloats[static_cast<FileData>(enumKey)] = floatNumber;
              
                }

                else if (enumKey == 3021)
                {
                    file >> floatNumber;
                    m_FileConfigFloats[static_cast<FileData>(enumKey)] = floatNumber;
              
                }

                else if (enumKey == 3022)
                {
                    file >> floatNumber;
                    m_FileConfigFloats[static_cast<FileData>(enumKey)] = floatNumber;
               
                }

                else if (enumKey == 3023)
                {
                    file >> floatNumber;
                    m_FileConfigFloats[static_cast<FileData>(enumKey)] = floatNumber;
             
                }

                else if (enumKey == 3024)
                {
                    file >> floatNumber;
                    m_FileConfigFloats[static_cast<FileData>(enumKey)] = floatNumber;
            
                }

                else if (enumKey == 3025)
                {
                    file >> floatNumber;
                    m_FileConfigFloats[static_cast<FileData>(enumKey)] = floatNumber;
          
                }
                ;
                 if (enumKey == 3026)
                {
                    file >> floatNumber;
                    m_FileConfigFloats[static_cast<FileData>(enumKey)] = floatNumber;
                 
                }
            }
        }
    }

}

bool FileManager::IsLoaded(FileData key)
{
    if (static_cast<int>(key) < 3014)
    {
        for (auto const& i : m_AssetFiles)
        {
            if (i.first == key)
            {
                std::cout << "Sound File Failed" << " " << static_cast<int>(key) << "\n";
                return true;
            }
        }
        return false;
    }

    if (static_cast<int>(key) > 3013  && static_cast<int>(key) < 3019)
    {
        for (auto const& i : m_FileConfigInts)
        {
            if (i.first == key)
            {
                std::cout << "Sound File Failed" << " " << static_cast<int>(key) << "\n";
                return true;
            }
        }
        return false;
    }


    if (static_cast<int>(key) > 3019)
    {
        for (auto const& i : m_FileConfigFloats)
        {
            if (i.first == key)
            {
                std::cout << "Sound File Failed" << " " << static_cast<int>(key) << "\n";
                return true;
            }
        }
        return false;
    }

}

// as it looks thru the file the first on eash line is the enum that == key the second is a string that == the file path asset
//  m_Assetfiles[ key ] = string;
FileManager::FileManager()
{
    Load();
}




