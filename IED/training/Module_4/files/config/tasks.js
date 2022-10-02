var AdvData = (function( advData ) {
    
    advData.tasks = [
        {
            "id"        : "intro_task",
            "subject"   : "Morning Huddle",
            "detail"    : "",
            "focus"     : 0,
            "focusNode" : "none",
            "status"    : "",
            "outcomes"  : {
                "ignored" : null,
                "complete" : null
            }
        },
        {
            "id"        : "task0",
            "duration"  : "1:00:00.00",
            "remaining" : "1:00:00.00",
            "isActive"  : false,
            "subject"   : "Nightly Plan",
            "detail"    : "Nightly Plan",
            "focusNode" : "none",
            "event"     : "startTask-nightlyPlan",
            "wasLate"   : false,
            "status"    : "",
            "customers" : {
                "max" : 2, 
                "deduction" : {
                    "service"   : 0,
                    "employee"  : 0,
                    "customer"  : -100,
                    "financial" : 0
                },
                "action" : Actions.nightlyPlan.tooManyCustomers,
                "text"   : "There were too many customers in the store when you began the Nightly Plan."
            },
            "conflicts" : [
                "trash-start",
                "trash-start2",
                "terminationNotice",
                "schedule",
                "greeting",
                "greetingPart2",
                "talkToCory",
                "happy_customer_event",
                "happy-sara",
                "angry-sara",
                "mystery-task-fail",
                "sales-task-start",
                "angry_customer_event",
                "inventory",
                "angry-customer2",
                "fight",                
                "closing_reminder_a",
                "lateAfternoonWorkSlow",
                "closing_reminder_c",
                "endOfDay"
            ],
            "outcomes" : {
                "complete"   : ['nightlyPlan','complete'],
                "ignored"    : ['nightlyPlan','ignored'],
                "incomplete" : ['nightlyPlan','incomplete']
            }
        },
        {
            "id"        : "task1",
            "isActive"  : false,
            "subject"   : "Customer is early",
            "detail"    : "There is a customer knocking at the door but the store is not yet opened",
            "focusNode" : "frontnode01",
            "focus"     : "earlyCustomer",
            "event"     : "startTask-earlyCustomer",
            "status"    : "",
            "onStart"   : Actions.earlyCustomer.startTask,
            "responseTime" : [
                {
                    "time" : "00:00:10",
                    action : "earlyCustomer_response",
                    result : "result1"
                },
                {
                    "time" : "00:00:15",
                    action : "earlyCustomer_response",
                    result : "result2"
                },
                {
                    "time" : "00:00:20",
                    action : "earlyCustomer_response",
                    result : "result3"
                },
                {
                    "time" : "00:00:30",
                    action : "earlyCustomer_response",
                    result : "result4"
                },
                {
                    action : "earlyCustomer_response",
                    result : "result5"
                }
            ],
            "outcomes" : {
                "ignored" : ['earlyCustomer','ignored'],
                "reply1" : null,
                "reply2" : null
            }
        },
        {
            "id"        : "task2",
            "isActive"  : false,
            "subject"   : "Customer at the front desk",
            "detail"    : "The customer you helped this morning would like to talk to you.",
            "focusNode" : "lobbynode03",
            "focus"     : "happyCustomer",
            "onStart"   : Actions.happyCustomer.startTask,
            "status"    : "",
            "responseTime" : [
                {
                    "time" : "00:00:10",
                    action : "happyCustomer_response",
                    result : "result1"
                },
                {
                    "time" : "00:00:15",
                    action : "happyCustomer_response",
                    result : "result2"
                },
                {
                    "time" : "00:00:20",
                    action : "happyCustomer_response",
                    result : "result3"
                },
                {
                    "time" : "00:00:30",
                    action : "happyCustomer_response",
                    result : "result4"
                },
                {
                    action : "happyCustomer_response",
                    result : "result5"
                }
            ],
            "outcomes"  : {
                "reply1" : null,
                "reply2" : null,
                "reply3" : null,
                "ignored" : null
            }
        },
        {
            "id"        : "task3",
            "isActive"  : false,
            "subject"   : "Customer at the front desk",
            "detail"    : "There is a customer waiting at the front desk who is not being waited on. He appears angry.",
            "focusNode" : "lobbynode03",
            "focus"     : "angryCustomer",
            "onStart"   : Actions.angryCustomer.startTask,
            "status"    : "",
            "responseTime" : [
                {
                    "time" : "00:00:10",
                    action : "angryCustomer_response",
                    result : "result1"
                },
                {
                    "time" : "00:00:15",
                    action : "angryCustomer_response",
                    result : "result2"
                },
                {
                    "time" : "00:00:30",
                    action : "angryCustomer_response",
                    result : "result3"
                },
                {
                    action : "angryCustomer_response",
                    result : "result4"
                }
            ],
            "outcomes"  : {
                "reply1" : null,
                "reply2" : null,
                "reply3" : null,
                "ignored" : null
            }
        },
        {
            "id"        : "morning_email",
            "isActive"  : false,
            "subject"   : "Check Morning Emails",
            "detail"    : "You have emails waiting in your inbox",
            "focusNode" : "officenode02",
            "focus"     : 5,
            "event"     : "startTask-emailTask",
            "onStart"   : Actions.email.startTask,
            "status"    : "",
            "outcomes"  : {
                "ignored" : ['email','ignored'],
                "wasRead" : ['email','wasRead']
            }
        },
        {
            "id"        : "email_task",
            "isActive"  : false,
            "subject"   : "Respond to Regional Manager",
            "detail"    : "Send a response to your Regional Manager addressing the congratulations he extended.",
            "focusNode" : "officenode02",
            "focus"     : 5,
            "onStart"   : Actions.email.startReplyTask,
            "status"    : "",
            "outcomes"  : {
                "ignored" : ['email_kudos_response','ignored'],
                "wasRead" : ['email_kudos_response','wasRead'],
                "reply1" : null,
                "reply2" : null, 
                "reply3" : null, 
                "reply4" : null
            }
        },
        {
            "id"        : "termination_task",
            "isActive"  : false,
            "subject"   : "Termination of Employee",
            "detail"    : "Terminate Lucas Broden",
            "focusNode" : "none",
            "event"     : "startTask-termination",
            "wasLate"   : false,
            "status"    : "",
            "completionTime" : [
                { 
                    "time" : "17:00:00", 
                    action : "termination_response",
                    result : "optimal"
                },
                {
                    action : "termination_response",
                    result : "fail"
                }
            ],
            "outcomes" : {
                "ignored" : ['termination_task','ignored'],
                "complete" : ['termination_task','complete']
            }
        },
        {
            "id"        : "meeting_task",
            "event"     : "startTask-dailyMeeting",
            "isActive"  : false,
            "subject"   : "Morning Huddle",
            "detail"    : "Start your Morning Huddle and discuss the day's agenda with your employees.",
            "focusNode" : "none",
            "wasLate"   : false,
            "status"    : "",
            "completionTime" : [
                // before 7:40 --> too early
                // 7:40 - 7:50 --> optinal time
                // 7:50 - 8:00 --> sub optimal
                // after 8:00  --> fail game
                {
                    "time" : "6:40:00",
                    action : "huddle_response",
                    result : "early"
                },
                {
                    "time" : "6:50:00", 
                    action : "huddle_response",
                    result : "optimal"
                },
                {
                    "time" : "7:00:00", 
                    action : "huddle_response",
                    result : "suboptimal"
                },
                {   // start after 7:00
                    action : "huddle_response",
                    result : "late"
                }
            ],
            "outcomes" : {
                "complete" : ['huddle','complete'],
                "ignored" : ['huddle','ignored']
            }
        },
        {
            "id"        : "task4",
            "subject"   : "Closing Reminder",
            "detail"    : "It is 5:00 pm, and you have 2 hours until closing. Your shop has more than 4 technicians working, but the volume of customers has slowed.",
            "focus"     : 0,
            "focusNode" : "none",
            "status"    : "",
            "onStart"   : Actions.closingB.startTask,
            "outcomes"  : {
                "ignored" : null,
                "reply1"  : null,
                "reply2"  : null,
                "reply3"  : null
            }
        },
        {
            "id"        : "complaint_task",
            "subject"   : "Customer at Front Desk",
            "detail"    : "There is a customer waiting at the front desk",
            "focusNode" : "lobbynode03",
            "focus"     : "angryCustomer",
            "status"    : "",
            "onStart"   : Actions.angryCustomer2.startTask,
            "outcomes"  : {
                "ignored" : null,
                "started" : null,
                "reply1" : null,
                "reply2" : null,
                "reply3" : null,
                "reply4" : null
            }
        },
        {
            "id"        : "fight_task",
            "subject"   : "Employees Fighting",
            "detail"    : "There are two employees fighting in the bay area.",
            "focusNode" : "upperbaynode01",
            "focus"     : "cory",
            "status"    : "",
            "onStart"   : Actions.fight.startTask,
            "outcomes"  : {
                "ignored" : null,
                "complete" : null,
                "reply1" : null,
                "reply2" : null,
                "reply3" : null,
                "reply4" : null
            }
        },
        {
            "id"        : "mystery_shopper",
            "subject"   : "Speak with Cory",
            "detail"    : "Cory arrived late for his shift. Speak with him about the morning announcements.",
            "focusNode" : "upperbaynode01",
            "focus"     : "cory",
            "status"    : "",
            "onStart"   : Actions.mysteryShopper.startTask,
            "outcomes"  : {
                "ignored"  : ['mysteryShopper_Cory0','ignored'],
                "complete" : ['mysteryShopper_Cory0','complete']
            }
        },
        {
            "id"        : "sales",
            "subject"   : "Email From Regional Manager",
            "detail"    : "You just got an important email from the Regional Manager.",
            "focusNode" : "officenode02",
            "focus"     : 5,
            "event"     : "startTask-salesEmail",
            "onStart"   : Actions.email.startTask,
            "status"    : "",
            "outcomes"  : {
                "ignored"  : null,
                "complete" : null
            }
        }
    ];
    
    return advData;
    
}( AdvData || {} ));