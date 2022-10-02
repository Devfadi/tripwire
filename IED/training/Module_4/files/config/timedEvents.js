var AdvData = (function( advData ) {
    
    advData.timedEvents = [
        {   // Add Chris to environment
            id       : "ChrisArrive",
            time     : "6:27:00.00",
            canShift : false,
            action   : Actions.employees.Chris.arrive,
            isActive : true,
            visited  : false
        },
        {   // Remind user to check tasks
            id       : "task_notification",
            time     : "6:28:30.00",
            canShift : false,
            action   : Actions.global.showTaskNotification,
            isActive : true,
            visited  : false
        },
        {   // notify user of email task
            id       : "email_task",
            time     : "6:30:00.00",
            canShift : false,
            event    : "timedEvent-email",
			fsm      : "gameState",
            isActive : true,
            visited  : false
        },
        {   // add Lucas
            id       : "lucasArrive",
            time     : "6:44:00.00",
            canShift : false,
            action   : Actions.employees.lucas.arrive,
            isActive : true,
            visited  : false
        },
        {   // notify user of late employee
            id       : "lateEmployee",
            time     : "6:45:00.00",
            canShift : false,
            event    : "timedEvent-lateEmployee",
            isActive : true,
            visited  : false
        },
        {   // start early customer event
            id       : "earlyCustomerTask",
            time     : "6:56:00.00",
            canShift : false,
            event    : "timedEvent-earlyCustomer",
            isActive : true,
            visited  : false
        },
        {   // Perform actions to open store
            id       : "openStore",
            time     : "7:00:00.00",
            canShift : false,
            action   : Actions.global.openStore,
            isActive : true,
            visited  : false
        },
        
        
        // *** All Events after this point could be skipped by performing the nightly plan activity
        
        
        {   // game fail if huddle not complete
            id       : "noMeetingFail",
            time     : "7:00:00.00",
            canShift : false,
            event    : "timedEvent-failMeeting",
            isActive : true,
            visited  : false
        },
        {   
            id       : "newEmployee",
            time     : "7:05:00.00",
            canShift : false,
            event    : "timedEvent-newEmployee",
            isActive : true,
            visited  : false
        },
        {
            id       : "tsb-start",
            time     : "7:20:00.00",
            event    : "timedEvent-tsb",
            isActive : true,
            visited  : false
        },
        {   
            id       : "trash-start",
            time     : "7:30:00.00",
            event    : "timedEvent-trash",
            isActive : true,
            visited  : false
        },
        {   
            id       : "trash-start2",
            time     : "7:40:00.00",
            event    : "timedEvent-trash2",
            isActive : false,
            visited  : false
        },
        {
            id       : "tsb-complaint",
            time     : "7:50:00.00",
            action   : Actions.tsb.customerComplaint,
            isActive : false,
            visited  : false
        },  
        {
            id       : "noHandle-start",
            time     : "8:15:00.00",
            action   : Actions.noHandle.activate,
            isActive : true,
            visited  : false
        },
        {   // notify user that lucas should be terminated
            id       : "terminationNotice",
            time     : "08:30:00.00",
            event    : "timedEvent-termination",
            isActive : true,
            visited  : false,
            onSkip   : Actions.termination.skipped,
            skipFail : true
        },
        {   
            id       : "lobby-event-1",
            time     : "08:35:00.00",
            event    : "timedEvent-misc1",
            isActive : true,
            visited  : false
        },
        {   
            id       : "lobby-event-1-timeout",
            time     : "08:40:00.00",
            action   : Actions.misc.timeoutEvent1,
            isActive : true,
            visited  : false
        },
        {   // show hint about checking library
            id       : "hint",
            time     : "09:00:00.00",
            action   : Actions.global.reportHint,
            isActive : true,
            visited  : false
        },
        {
            id       : "serviceTimes",
            time     : "10:30:00.00",
            event    : "timedEvent-serviceTimes",
            isActive : true,
            visited  : false
        },
        {   // morning shift change
            id       : "morningShift",
            time     : "10:58:00.00",
            action   : Actions.global.morningShift,
            isActive : true,
            visited  : false,
            onSkip   : Actions.global.morningShift,
            skipFail : false
        },
        {   // Scheduling conflict
            id       : "schedule",
            time     : "11:00:00.00",
            event    : "timedEvent-schedule",
            isActive : true,
            visited  : false
        },
        {   // Improper Greeting start
            id       : "greeting",
            time     : "11:15:00.00",
            event    : "timedEvent-greeting",
            isActive : true,
            visited  : false
        },
        {   // Improper Greeting
            id       : "greetingPart2",
            time     : "11:20:00.00",
            event    : "timedEvent-greeting2",
            isActive : false,
            visited  : false
        },
        {   // add cory to environment
            id       : "tech3",
            time     : "11:29:30.00",
            canShift : false,
            action   : Actions.employees.cory.arrive,
            isActive : true,
            visited  : false,
            onSkip   : Actions.employees.cory.arrive, // if event skipped still place cory in environment
            skipFail : false
        },
        {   // approach cory after arrived late
            id       : "talkToCory",
            time     : "11:30:00.00",
            canShift : true,
            event    : "timedEvent-talkToCory",
            isActive : true,
            visited  : false,
            onSkip   : Actions.mysteryShopper.skipped,
            skipFail : false
        },
        {
            id       : "happy-sara",
            time     : "12:00:00.00",
            event    : "timedEvent-happySara",
            isActive : false,
            visited  : false
        },
        {
            id       : "angry-sara",
            time     : "12:00:00.00",
            event    : "timedEvent-angrySara",
            isActive : false,
            visited  : false
        },
        {
            id       : "oilSpill-start",
            time     : "12:15:00.00",
            event    : "timedEvent-oilSpill",
            isActive : true,
            visited  : false
        },
        {
            id       : "afterService-start",
            time     : "12:45:00.00",
            event    : "timedEvent-afterService",
            isActive : true,
            visited  : false
        },
        {
            id       : "eyewear-start",
            time     : "13:15:00.00",
            event    : "timedEvent-eyewear",
            isActive : true,
            visited  : false
        },
        {   // if mystery shopper task has not been addressed, task fail
            id       : "mystery-task-fail",
            time     : "14:00:00.00",
            event    : "timedEvent-failMysteryShopper",
            isActive : true,
            visited  : false
        },
        {   // if mystery shopper task has not been addressed, task fail
            id       : "sales-task-start",
            time     : "14:05:00.00",
            action   : Actions.sales.activateTask,
            isActive : false,
            visited  : false
        },
        {
            id       : "radiator-start",
            time     : "14:15:00.00",
            event    : "timedEvent-radiator",
            isActive : true,
            visited  : false
        },
        {   
            id       : "lobby-event-2",
            time     : "14:30:00.00",
            event    : "timedEvent-misc2",
            isActive : true,
            visited  : false
        },
        {   
            id       : "lobby-event-2-timeout",
            time     : "14:35:00.00",
            action   : Actions.misc.timeoutEvent2,
            isActive : true,
            visited  : false
        },
        {
            id       : "afternoon-customer-slowdown",
            time     : "15:00:00.00",
            action   : Actions.global.slowdown,
            isActive : true,
            visited  : false
        },
        {   // if positive outcome to early customer, show happy customer
            id       : "happy_customer_event",
            time     : "15:30:00.00",
            //event    : "timedEvent-happyCustomer",
            action   : Actions.happyCustomer.start,
            isActive : false,
            visited  : false
        },
        {   // if negative otucome to early customer, show angry customer
            id       : "angry_customer_event",
            time     : "15:30:00.00",
            //event    : "timedEvent-angryCustomer",
            action   : Actions.angryCustomer.start,
            isActive : false,
            visited  : false
        },
        {   // notify player customer is still waiting
            id       : "happy-customer-wait",
            time     : "15:30:15.00",
            action   : Actions.happyCustomer.stillWaiting,
            isActive : false,
            visited  : false
        },
        {   
            id       : "angry-customer-wait",
            time     : "15:30:15.00",
            action   : Actions.angryCustomer.stillWaiting,
            isActive : false,
            visited  : false
        },
        {   // inventory
            id       : "inventory",
            time     : "16:00:00.00",
            event    : "timedEvent-inventory",
            isActive : true,
            visited  : false
        },
        {
            id       : "bayNet-start",
            time     : "16:15:00.00",
            event    : "timedEvent-bayNet",
            isActive : true,
            visited  : false
        },
        {   // can no longer complete termination task after this point
            id       : "bayInjury",
            time     : "16:25:00.00",
            event    : "timedEvent-injury",
            isActive : false,
            visited  : false
        },
        // {   // can no longer complete termination task after this point
            // id       : "termination-fail",
            // time     : "16:30:00.00",
            // action   : Actions.termination.timeUp,
            // onSkip   : Actions.termination.timeUp,
            // isActive : true,
            // visited  : false
        // },
        {
            id       : "afternoon-customer-speedup",
            time     : "16:25:00.00",
            action   : Actions.global.speedup,
            isActive : true,
            visited  : false
        },
        {   
            id       : "angry-customer2",
            time     : "16:30:00.00",
            event    : "timedEvent-angryCustomer2",
            isActive : true,
            visited  : false
        },
        {   
            id       : "angry-customer2-midpoint",
            time     : "16:30:15.00",
            action   : Actions.angryCustomer2.midpoint,
            isActive : false,
            visited  : false
        },
        {
            id       : 'angry-customer2-expires',
            time     : '16:30:30',
            action   : Actions.angryCustomer2.failTask,
            isActive : false,
            visited  : false
        },
        
        // otherwise show fight sequence
        
        {   // Fight Sequence start
            id       : "fight",
            time     : "16:40:00.00",
            event    : "timedEvent-fight",
            isActive : true,
            visited  : false,
            onSkip   : Actions.fight.skipped,
            skipFail : true
        },
        {   // if fight still occuring warn player
            id       : "fightWarn",
            time     : "16:50:20.00",
            action   : Actions.fight.notify,
            isActive : false,
            visited  : false
        },
        {   // if fight still occuring, cause fail
            id       : "fightFail",
            time     : "16:50:40.00",
            event    : "timedEvent-fightFail",
            isActive : false,
            visited  : false
        },
        {   // Afternoon Shift Change
            id       : "afternoon",
            time     : "17:00:00",
            action   : Actions.global.afternoonShift,
            onSkip   : Actions.global.afternoonShift,
            isActive : true,
            visited  : false
        },
        {   // closing reminder A
            id       : "closing_reminder_a",
            time     : "17:01:00",
            event    : "timedEvent-closingA",
            isActive : true,
            visited  : false
        },
        {   // closing reminder B
            id       : "lateAfternoonWorkSlow",
            time     : "17:15:00.00",
            event    : "timedEvent-closingB",
            isActive : true,
            visited  : false
        },
        {
            id       : "closingActivity",
            time     : "18:30:00.00",
            event    : "timedEvent-closingActivity",
            isActive : true,
            visited  : false
        },
        {   // closing reminder C
            id       : "closing_reminder_c",
            time     : "18:45:00",
            event    : "timedEvent-closingC",
            isActive : true,
            visited  : false
        }, 
        {   // End Of Day, stop clock, score any remaining tasks
            id       : "endOfDay",
            time     : "19:00:00.00",
            action   : Actions.endOfDay.start,
            isActive : true,
            visited  : false
        }
    ];
    
    return advData;
}( AdvData || {} ));