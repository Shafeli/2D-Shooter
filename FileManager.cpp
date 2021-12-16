#include "FileManager.h"

void FileManager::SaveHighScore(int data)
{
}

std::string FileManager::GetFilePath(FileData name)
{
    return this->m_AssetFiles.at(name);
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
                //front file
                //textures
                //sounds
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
               // FilePathLoader(enumKey, &file);
                continue;
            }
            else if (enumKey > 3013 && enumKey < 3018)
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
                //ints
               // IntLoader(enumKey, &file);
                continue;
            }
            else if (enumKey > 3018)
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
                //floats
               // FloatLoader(enumKey, &file);

            }
        }
    }

}

FileManager::FileManager()
{
    Load();
}

//void FileManager::IntLoader(int& enumkey, std::ifstream* file)
//{          
//    int cast = enumkey;
//    int intNumber;
//    if (enumkey == 14)
//    {
//        file >> intNumber;
//        m_FileConfigInts[static_cast<FileData>(cast)] = intNumber;
//        return;
//    }
//  
//    if (enumkey == 15)
//    {
//        file >> intNumber;
//        m_FileConfigInts[static_cast<FileData>(cast)] = intNumber;
//        return;
//    }
//
//    if (enumkey == 16)
//    {
//        file >> intNumber;
//        m_FileConfigInts[static_cast<FileData>(cast)] = intNumber;
//        return;
//    }
//   
//    if (enumkey == 17)
//    {
//        file >> intNumber;
//        m_FileConfigInts[static_cast<FileData>(cast)] = intNumber;
//        return;
//    }
//
//    if (enumkey == 18)
//    {
//        file >> intNumber;
//        m_FileConfigInts[static_cast<FileData>(cast)] = intNumber;
//        return;
//    }
//
//}
//
//void FileManager::FloatLoader(int& enumkey, std::ifstream* file)
//{
//    float floatNumber;
//    int cast = enumkey;
//    if (enumkey == 19)
//    {
//        file >> floatNumber;
//        m_FileConfigFloats[static_cast<FileData>(cast)] = floatNumber;
//        return;
//    }
//
//    if (enumkey == 20)
//    {
//        file >> floatNumber;
//        m_FileConfigFloats[static_cast<FileData>(cast)] = floatNumber;
//        return;
//    }
//
//    if (enumkey == 21)
//    {
//        file >> floatNumber;
//        m_FileConfigFloats[static_cast<FileData>(cast)] = floatNumber;
//        return;
//    }
//
//    if (enumkey == 22)
//    {
//        file >> floatNumber;
//        m_FileConfigFloats[static_cast<FileData>(cast)] = floatNumber;
//        return;
//    }
//
//    if (enumkey == 23)
//    {
//        file >> floatNumber;
//        m_FileConfigFloats[static_cast<FileData>(cast)] = floatNumber;
//        return;
//    }
//
//    if (enumkey == 24)
//    {
//        file >> floatNumber;
//        m_FileConfigFloats[static_cast<FileData>(cast)] = floatNumber;
//        return;
//    }
//
//    if (enumkey == 25)
//    {
//        file >> floatNumber;
//        m_FileConfigFloats[static_cast<FileData>(cast)] = floatNumber;
//        return;
//    }
//    ;
//    if (enumkey == 26)
//    {
//        file >> floatNumber;
//        m_FileConfigFloats[static_cast<FileData>(cast)] = floatNumber;
//        return;
//    }
//}
//
//void FileManager::FilePathLoader(int& enumkey, std::ifstream* file)
//{
//    std::string word;
//    int cast = enumkey;
//    if (enumkey == 1)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
// 
//    if (enumkey == 2)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
// 
//    if (enumkey == 3)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
// 
//    if (enumkey == 4)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
// 
//    if (enumkey == 5)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//  
//    if (enumkey == 6)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//  
//    if (enumkey == 7)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//    if (enumkey == 8)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//
//    if (enumkey == 9)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//
//    if (enumkey == 10)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//
//    if (enumkey == 11)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//
//    if (enumkey == 12)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//
//    if (enumkey == 13)
//    {
//        file >> word;
//        m_AssetFiles[static_cast<FileData>(cast)] = word;
//        return;
//    }
//}

// as it looks thru the file the first on eash line is the enum that == key the second is a string that == the file path asset


//  m_Assetfiles[ key ] = string;



    //file >> word;
    //if (word == "randomMoney")
    //{
    //    // step randomMoney
    //    pGameObject->AddStepStrat(new GameObjectGiveMoneyStrat(amount));
    //}
    //else if (word == "changeOwnAppearance")
    //{
    //    // step changeOwnAppearance = char '#' color int = 14
    //    file >> appearance;
    //    file >> color;
    //    pGameObject->AddStepStrat(new ChangeAppearnceStrat(*pGameObject, appearance, color));
    //}
    //else if (word == "damage")
    //{
    //    // step damage
    //    pGameObject->AddStepStrat(new GameObjectDmgStrat(amount));
    //}
    //else if (word == "killSelf")
    //{
    //    // step killSelf
    //    pGameObject->AddStepStrat(new GameObjectKillOwner(*pGameObject));
    //}
    //else if (word == "end")
    //{
    //    // step end
    //    pGameObject->AddStepStrat(new GameObjectEndStrat(*pGameObject));
    //}