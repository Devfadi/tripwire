Table Of Contents
- Engine Files
- Configuring your app...
- 


┌───────────────┐
│ Engine Files: │
└───────────────┘
Here is a brief description of the Adventure Engine's main components:

┌─engine.js                 ►   main engine script
│
├─internal/                 ►   SCRIPTS USED INTERNALLY BY ENGINE COMPONENTS
│ ├─advEvent.js             ►   custom event
│ ├─advStateMachine.js      ►   state machine class
│ └─advVariable.js          ►   variable class
│
├─krpano/                   ►   KRPANO EXTENSION
│ │                             ( a set of components responsible for using 3D Panorama media )
│ ├─camera.js               ►   manages the camera properties
│ ├─entities.js             ►   manages entities in pano
│ ├─entity.js               ►   entity object
│ ├─hotspots.js             ►   manages hotspots
│ ├─input.js                ►   input controls
│ ├─krpano.js               ►   main krpano script
│ └─player.js               ►   controls the player
│
├─modules/                  ►   ENGINE MODULES THAT PROVIDE CORE FUNCTIONALITY 
│ │                             ( these directly extend the aden/AdvEngine object )
│ ├─clock.js                ►   tracks engine time
│ ├─layers.js               ►   manages visual layers
│ ├─objectFactory.js        ►   generates adventure objects
│ ├─objects.js              ►   manages adventure objects
│ ├─save.js                 ►   creates save data
│ ├─score.js                ►   tracks score
│ ├─timedEvents.js          ►   manages timed events
│ └─variables.js            ►   manages shared variables that are saved between sessions.
│
├─objects/                  ►   ENGINE ADVENTURE OBJECTS
│ │                             ( these are media items that are generated during gameplay )
│ ├─advObject.js            ►   base object script
│ ├─advAudio.js             ►   handles the playback of audio
│ ├─advDP.js                ►   displays a decision point prompt
│ ├─advImage.js             ►   displays an image
│ ├─advNarration.js         ►   displays a narration object
│ ├─advPopup.js             ►   displays a popup or prompt
│ └─advVideo.js             ►   handles the playback of video
│
└─plugins/                  ►   ENGINE PLUGINS THAT PROVIDE ADDON FUNCTIONALITY 
  │                             ( these are intended to allow for one or more instances )
  ├─advPlugin.js            ►   base plugin script
  ├─advClock.js             ►   a plugin for displaying the game play time
  ├─advNotification.js      ►   a plugin for displaying notifications
  ├─advOverlay.js           ►   a plugin for generating overlays which block user input
  ├─advReview.js            ►   a plugin for generating an after action review
  ├─advScoreDisplay.js      ►   a plugin for displaying the current score
  └─advTracker.js           ►   a plugin for tracking objectives and user feedback
