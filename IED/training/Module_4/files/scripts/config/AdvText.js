define(function(require){
    var text = {
        splash: {
            image: "files/assets/images/screens/scenario_01/IntroImage.png",
            title: "IED Interactive Scenarios",
            description: "<p>Welcome to IED Interactive Scenarios for Public Safety Responders. These scenarios are designed to heighten your awareness and reaction skills for an initial on-scene response to an IED event. The goal is to develop your situational awareness and critical thinking skills for responding to IED threat situations in a variety of circumstances and environments.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p></br/><p>Click Start below to begin. Click Skip to go to the Scenario Menu.</p>"
        },
        introduction : {
            "text": "",
            "img": "files/assets/images/screens/scenario_01/IntroImage.png"
        },
        instructions : [
            /*{
                "text": "New Screen 1",
                "img":"files/assets/images/screens/intro/arrow-screen.png"
            },
            {
                "text": "New Screen 2",
                "img":"files/assets/images/screens/intro/arrow-screen.png"
            },*/
            {
                "text": "<p>Take a moment to make sure your computer meets the basic technical requirements to run this training.</p><br/><h1 style=' width: 100%; text-align: center;'>Technical Requirements</h1><p style=' width: 100%; text-align: center;'>If you haven't done so, please take a moment to read the <a href=\"Installation Instructions.pdf\" target=\"_blank\">Installation Instructions</a> document.</p><br/><table><tr><td style='width: 40%; padding-right: 2em;'><ul><li><strong>Browser:</strong> HTML5 compliant (Internet Explorer 10, Chrome 20, Firefox 10, or Safari 5.1)</li><li><strong>Audio:</strong> Sound card with speakers or headphones</li><li><strong>Screen resolution:</strong> 1280 x 1024 (recommended)</li><li><strong>Flash:</strong> If browser requires Adobe Flash to run this course, download and install the Adobe Flash Player: <a href='http://get.adobe.com/flashplayer/' target=\"_blank\">http://get.adobe.com/flashplayer/</a></li></ul></td><td><ul><li><p><strong>ActiveX (Internet Explorer only):</strong> In IE, disable ActiveX Filtering for <span class='em'>this site</span> by selecting:</p><ol><li>Filter button in the address bar, then</li><li>\"Turn off ActiveX Filtering\"</li></ol><p>If the Filter button doesn't appear in the address bar, no ActiveX content is being filtered, which is the desired state.</p><p>To turn off ActiveX Filtering for <span class='em'>all sites</span>, select:</p><ol><li>Tools button</li><li>\"Safety\" from the dropdown menu, and then</li><li>ActiveX Filtering</li></ol><p>There should no longer be a checkmark next to ActiveX Filtering.</p></li></ul></td></tr></table>",
                "img":""
            },
            {
                "text": "<h1>Changing Location/Looking Around</h1><p>At times the program will prompt you to change location or look around. You may also look around anytime the LOOK AROUND indicator is in the upper left of the screen.</p><ul><li><strong>Change Location </strong>– When an arrow icon appears in the environment, click the arrow to change location.</li><li><strong>Look Around </strong>– Use the arrow keys on your keyboard to look around or left click your mouse on the scene and drag your view.<br/><img src='files/assets/images/screens/intro/arrowkeys.png'/></li><li><strong>Zoom </strong>– Anytime the LOOK AROUND indicator is displayed, use the scroll wheel on your mouse to zoom in and out.</li></ul><br/><h1>Full Screen Support</h1><p>Press the 'F11' key at any time to toggle full-screen view on or off.</p>",
                "img":""
            },
            {
                "text": "<h1>Timer Bar</h1><p>The Timer Bar at the top of the screen counts down in seconds and changes from green to yellow to red as your time to perform a task expires.</p><br/><h1>Microphone</h1><p>In the opening screen, the microphone will highlight when you are receiving a message over the radio. Clicking the microphone acknowledges that you are responding to the message.</p>",
                "img":"files/assets/images/screens/intro/timer.png"
            },
            {
                "text": "<h1>Resources</h1><ul><li>Click the tab on the left side of the screen to access the Resources menu. These resources include job aids to help you identify IEDs and their components, decide how best to respond in a given situation, and complete the scenarios successfully. A Help file, which provides program instructions, is also found in the Resources tab.</li><li>Clicking STOP on the Resources menu ends the scenario you are in. From there you can restart the scenario by clicking RESTART, or access the Scenario menu by clicking MENU.</li></ul><br/><h1>Start</h1><p>Clicking Start in the lower left corner of the screen starts the scenario you have selected.</p>",
                "img":"files/assets/images/screens/intro/resources.png"
            },
            {
                "text": "<h1>Resources</h1><p>In each scenario you'll be asked to use the Five Cs procedure to respond to the IED threat situation. Take a moment to revew the Five Cs.  This and other helpful information is always available within the scenarios under the Resources tab.</p><p><a href=\"files/assets/pdf/First Responder Safety Card v5.pdf\" target=\"_blank\">First Responder Safety Card</a></p>",
                "img":"files/assets/images/screens/intro/5C_screen.png"
            }
        ],
        scenario01: {
            img: "files/assets/images/screens/scenario_01/IntroImage.png",
            title: "Scenario 1 - Introductory Scenario",
            description: "<p>In this scenario you play the role of a police officer responding to a call outside the Federal Courthouse downtown.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        },
        scenario02: {
            img: "files/assets/images/screens/scenario_02/IntroImage.png",
            title: "Scenario 2",
            description: "<p>In this scenario you play the role of a mass transit police officer responding to a call at the city’s main train station.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        },
        scenario03: {
            img: "files/assets/images/screens/scenario_03/IntroImage.png",
            title: "Scenario 3",
            description: "<p>In this scenario you play the role of a first responder working as game-day security at the local university’s stadium.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        },
        scenario04: {
            img: "files/assets/images/screens/scenario_04/IntroImage.png",
            title: "Scenario 4",
            description: "<p>In this scenario you play the role of an EMT responding to a call for medical assistance in a rural area of the county.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        },
        scenario05: {
            img: "files/assets/images/screens/scenario_05/IntroImage.png",
            title: "Scenario 5",
            description: "<p>In this scenario you play the role of a police officer responding to an emergency call at a downtown high school.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        },
        scenario06: {
            img: "files/assets/images/screens/scenario_06/IntroImage.png",
            title: "Scenario 6",
            description: "<p>In this scenario you play the role of an EMT responding to a traffic accident at one of the city’s busier intersections.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        },
        scenario07: {
            img: "files/assets/images/screens/scenario_07/IntroImage.png",
            title: "Scenario 7",
            description: "<p>In this scenario you play the role of a police officer on patrol in a large city.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        },
        scenario08: {
            img: "files/assets/images/screens/scenario_08/IntroImage.png",
            title: "Scenario 8",
            description: "<p>In this scenario you play the role of a volunteer fire crew member responding to a report of a brush fire near a rest area.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        },
        scenario09: {
            img: "files/assets/images/screens/scenario_09/IntroImage.png",
            title: "Scenario 9",
            description: "<p>In this scenario you play the role of a police officer responding to a call of an unknown disturbance in the outdoor amphitheater’s parking lot.</p><p class='info-text'><strong>Note:</strong> The information provided within this training serves as a guide to assist responders with assessing a potential IED incident and recommended actions on a find. It does not supersede existing agency processes, protocols, or procedures.</p><p>Click Start to begin. Click Back to return to the Scenario Menu.</p>"
        }
    };
    
    return text;
});
