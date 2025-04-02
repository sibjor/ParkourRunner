#include "central.hpp"

std::vector<std::string> Artwork::PrepareAssets()
{
    std::vector<std::string> assetsVector;
    Artwork *artwork = new Artwork();
    // Add player movement pack assets
    for(int i = 0; i < artwork->playerMovementPack.size(); i++ ){
        assetsVector.push_back(artwork->playerMovementPack[i]);
    }
    // Add player vault pack assets
    for(int i = 0; i < artwork->playerVaultPack.size(); i++ ){
        assetsVector.push_back(artwork->playerVaultPack[i]);
    }
    return assetsVector;
}
