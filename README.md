 </a><p align=center>[![General badge](https://img.shields.io/badge/Large&nbsp;Textile&nbsp;Normals-v1.0-<COLOR>.svg)](https://github.com/ScottRaffertyCG/MaterialVault/releases/tag/production/)
<a href="LICENSE.md"><img src="https://img.shields.io/badge/License-MIT-blue.svg"></a>

# ![Logo](Logo_materialVault_v002.png)

## Description

Fully dynamic material library folder scanning and generation system. texture dependence viewer as well as live metadata viewing and editing. 

## Getting Started

### Installing

This plugin is a self contained Unreal Engine 5.3 plugin. Place the **Entire** folder into either your Project/Plugins folder (if Plugins does not exist you can create it) or place it in your engine installation directory under Engine/Plugins

### Loading the interface

* Open your Unreal Engine project
* Navigate to the main editor toolbar and find the palette button (Hovering over this helpfully tells you Open the Material Vault Library Interface.)

 ![Plugin Window Interface 1](MV_Load.gif)

 ![Plugin Window Interface 2](PluginThumbnail.png)

## Help

* Displacement is currently disabled for this initial release. It is in active development but until a future UE version is released that does not involve eidting the config files I do not think it's best to implement displacement at this early stage. 

* Metadata is 95% working. Some kinks to iron out with Author and Modified Date.

* The release section has the latest large files that conventional Git would remove as they are >100MB. Download these and place them in the 
\Plugins\MaterialVault\MaterialVault\Content\MaterialVault\Textures\Normals folder

* In order to incorporate multiple button functions, descisions had to be made for the controls of the LMB,RMB and MMB.
	* Left Click selects the asset in the content browser
	* Right Click applys the asset to the static mesh
	* Middle Mouse Button opens up a larger thumbnail preview of this material. 

for version 1.1 I will be looking at better ways to handle all three functions in a more intuitive way.

## Authors


Scott Rafferty

[![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/scott-rafferty/)


info@scottrafferty.co.uk

## Version History

* v1.0
    * Initial Release

## License

This project is licensed under [MIT](LICENSE.md).

## Acknowledgments

Epic Games - [Automotive Materials Pack](https://www.unrealengine.com/id/login/api/login?client_id=43e2dea89b054198a703f6199bee6d5b&redirect_uri=https%3A%2F%2Fwww.unrealengine.com%2Fmarketplace%2Fen-US%2Fproduct%2Fautomotive-material-pack%3FsessionInvalidated%3Dtrue&prompt=pass_through). 

All extra textures are CC0 licenses and have been sourced from various sites such as [AmbientCG](https://ambientcg.com/) and [CC0 Textures](https://cc0-textures.com/)
