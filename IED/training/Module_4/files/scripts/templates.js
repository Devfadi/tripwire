define(['handlebars'], function(Handlebars) {

this["JST"] = this["JST"] || {};

this["JST"]["files/templates/objects/audio.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression;


  buffer += "<div id=\"";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" class=\"layer\">\r\n    <div class=\"jp-jplayer\"></div>\r\n    <div class=\"jp-audio\">\r\n        <div class=\"jp-type-single\">\r\n            <div class=\"jp-gui jp-interface\">\r\n                <ul class=\"jp-controls\">\r\n                    <li>\r\n                        <a href=\"javascript:;\" class=\"jp-play\" tabindex=\"1\">play</a>\r\n                    </li>\r\n                    <li>\r\n                        <a href=\"javascript:;\" class=\"jp-pause\" tabindex=\"1\">pause</a>\r\n                    </li>\r\n                </ul>\r\n            </div>\r\n        </div>\r\n    </div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/audio_control.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "";


  return buffer;
  });

this["JST"]["files/templates/objects/audio_oldController.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div class=\"jp-audio\">\r\n    <div class=\"jp-type-single\">\r\n        <div class=\"jp-gui jp-interface\">\r\n            <ul class=\"jp-controls\">\r\n                <li>\r\n                    <a href=\"javascript:;\" class=\"jp-play\" tabindex=\"1\">play</a>\r\n                </li>\r\n                <li>\r\n                    <a href=\"javascript:;\" class=\"jp-pause\" tabindex=\"1\">pause</a>\r\n                </li>\r\n                <li>\r\n                    <a href=\"javascript:;\" class=\"jp-stop\" tabindex=\"1\">stop</a>\r\n                </li>\r\n                <li>\r\n                    <a href=\"javascript:;\" class=\"jp-mute\" tabindex=\"1\" title=\"mute\">mute</a>\r\n                </li>\r\n                <li>\r\n                    <a href=\"javascript:;\" class=\"jp-unmute\" tabindex=\"1\" title=\"unmute\">unmute</a>\r\n                </li>\r\n                <li>\r\n                    <a href=\"javascript:;\" class=\"jp-volume-max\" tabindex=\"1\" title=\"max volume\">max volume</a>\r\n                </li>\r\n            </ul>\r\n            <div class=\"jp-progress\">\r\n                <div class=\"jp-seek-bar\">\r\n                    <div class=\"jp-play-bar\"></div>\r\n                </div>\r\n            </div>\r\n            <div class=\"jp-volume-bar\">\r\n                <div class=\"jp-volume-bar-value\"></div>\r\n            </div>\r\n            <div class=\"jp-time-holder\">\r\n                <div class=\"jp-current-time\"></div><div class=\"jp-duration\"></div>\r\n                <ul class=\"jp-toggles\">\r\n                    <li>\r\n                        <a href=\"javascript:;\" class=\"jp-repeat\" tabindex=\"1\" title=\"repeat\">repeat</a>\r\n                    </li>\r\n                    <li>\r\n                        <a href=\"javascript:;\" class=\"jp-repeat-off\" tabindex=\"1\" title=\"repeat off\">repeat off</a>\r\n                    </li>\r\n                </ul>\r\n            </div>\r\n        </div>\r\n        <div class=\"jp-title\">\r\n            <ul>\r\n                <li>\r\n                    title\r\n                </li>\r\n            </ul>\r\n        </div>\r\n        <div class=\"jp-no-solution\">\r\n            <span>Update Required</span>To play the media you will need to either update your browser to a recent version or update your <a href=\"http://get.adobe.com/flashplayer/\" target=\"_blank\">Flash plugin</a>.\r\n        </div>\r\n    </div>\r\n</div>";
  });

this["JST"]["files/templates/objects/audio_player.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "";


  return buffer;
  });

this["JST"]["files/templates/objects/dp-multi.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n            <li><a href='#' id=\"";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" class='adv-dp-option' data-adv-option=\"";
  if (helper = helpers.index) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.index); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">";
  if (helper = helpers.text) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.text); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</a></li>\r\n            ";
  return buffer;
  }

  buffer += "<div class='adv-dp'>\r\n    <div class=\"adv-dp-content\">\r\n        <p class='stem border-rounded question-text'>\r\n            ";
  if (helper = helpers.stem) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.stem); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        </p>\r\n        <ul class='options'>\r\n            ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.options), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        </ul>\r\n        <div class='adv-dp-button'>Submit</div>\r\n    </div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/dp.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n            <li><a href='#' id=\"";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" class='adv-dp-option' data-adv-option=\"";
  if (helper = helpers.index) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.index); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">";
  if (helper = helpers.text) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.text); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</a></li>\r\n            ";
  return buffer;
  }

  buffer += "<div class='adv-dp'>\r\n    <div class=\"adv-dp-content\">\r\n        <p class='stem border-rounded question-text'>\r\n            ";
  if (helper = helpers.stem) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.stem); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        </p>\r\n        <ul class='options'>\r\n            ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.options), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        </ul>\r\n    </div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/dpManaged.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n        <li>\r\n            <a href='#' id='";
  if (helper = helpers.event) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.event); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "'>";
  if (helper = helpers.text) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.text); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</a>\r\n        </li>\r\n        ";
  return buffer;
  }

  buffer += "<div class='decisionPoint'>\r\n    <p class='stem'>\r\n        ";
  if (helper = helpers.stem) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.stem); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    </p>\r\n    <ul class='options'>\r\n        ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.options), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    </ul>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/dpMulti.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "";


  return buffer;
  });

this["JST"]["files/templates/objects/dpMultiManaged.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n            <li class='option-text'>\r\n                <a href='#' id='";
  if (helper = helpers.event) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.event); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "' class='border-rounded'>";
  if (helper = helpers.text) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.text); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</a>\r\n            </li>\r\n            ";
  return buffer;
  }

  buffer += "<div class='decisionPoint'>\r\n    <div class='adv-dp-content'>\r\n        <p class='stem border-rounded question-text'>\r\n            ";
  if (helper = helpers.stem) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.stem); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        </p>\r\n        <ul class='options'>\r\n            ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.options), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n            <div class='adv-dp-button' style='margin-top:10px;'>\r\n                Submit\r\n            </div>\r\n        </ul>\r\n    </div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/image.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression;


  buffer += "<div class=\"layer adv-image\">\r\n    <img src=\"";
  if (helper = helpers.src) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.src); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\"/>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/narration.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function";


  buffer += "<div class='adv-dp'>\r\n    <div class=\"adv-dp-content\">\r\n        ";
  if (helper = helpers.text) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.text); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    </div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/narrator.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div class='adv-narrator'>\r\n    <div class=\"adv-narrator-image\"></div>\r\n    <div class=\"adv-narrator-content\">\r\n        <div class='adv-narrator-content-bg layer border-white border-rounded'></div>\r\n        <div class='adv-narrator-text'></div>\r\n    </div>\r\n";
  });

this["JST"]["files/templates/objects/notification.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div class='adv-notifcation'><div>";
  });

this["JST"]["files/templates/objects/popup.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function";


  buffer += "<div>\r\n	<p>";
  if (helper = helpers.text) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.text); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</p>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/scorePopup.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function";


  buffer += "<p>";
  if (helper = helpers.stem) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.stem); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</p>";
  return buffer;
  });

this["JST"]["files/templates/objects/video.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n        <source type=\"";
  if (helper = helpers.type) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.type); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" src=\"";
  if (helper = helpers.file) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.file); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">\r\n        ";
  return buffer;
  }

  buffer += "<div id=\"";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" class=\"layer layer-overlay adv-video\">\r\n    <!--\r\n    <video id=\"video-";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" class=\"video-player video-layer video-js vjs-default-skin\" controls width=\"1280\" height=\"720\" poster=\"";
  if (helper = helpers.poster) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.poster); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" preload=\"auto\">\r\n        ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.source), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    </video>\r\n    <div id=\"video-";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "-control\" class=\"video-control jp-gui\"></div>\r\n    -->\r\n    <div id=\"jp_container_1\" class=\"jp-video\">\r\n        <div class=\"jp-type-single\">\r\n            <div id=\"jquery_jplayer_1\" class=\"jp-jplayer\"></div>\r\n            <div class=\"jp-gui\">\r\n                <div class=\"jp-video-play\">\r\n                    <a href=\"javascript:;\" class=\"jp-video-play-icon\" tabindex=\"1\">play</a>\r\n                </div>\r\n                <div class=\"jp-interface\">\r\n                    <div class=\"jp-progress\">\r\n                        <div class=\"jp-seek-bar\">\r\n                            <div class=\"jp-play-bar\"></div>\r\n                        </div>\r\n                    </div>\r\n                    <div class=\"jp-current-time\"></div>\r\n                    <div class=\"jp-duration\"></div>\r\n                    <div class=\"jp-controls-holder\">\r\n                        <ul class=\"jp-controls\">\r\n                            <li><a href=\"javascript:;\" class=\"jp-play\" tabindex=\"1\">play</a></li>\r\n                            <li><a href=\"javascript:;\" class=\"jp-pause\" tabindex=\"1\">pause</a></li>\r\n                            <li><a href=\"javascript:;\" class=\"jp-stop\" tabindex=\"1\">stop</a></li>\r\n                            <li><a href=\"javascript:;\" class=\"jp-mute\" tabindex=\"1\" title=\"mute\">mute</a></li>\r\n                            <li><a href=\"javascript:;\" class=\"jp-unmute\" tabindex=\"1\" title=\"unmute\">unmute</a></li>\r\n                            <li><a href=\"javascript:;\" class=\"jp-volume-max\" tabindex=\"1\" title=\"max volume\">max volume</a></li>\r\n                        </ul>\r\n                        <div class=\"jp-volume-bar\">\r\n                            <div class=\"jp-volume-bar-value\"></div>\r\n                        </div>\r\n                        <ul class=\"jp-toggles\">\r\n                            <li><a href=\"javascript:;\" class=\"jp-full-screen\" tabindex=\"1\" title=\"full screen\">full screen</a></li>\r\n                            <li><a href=\"javascript:;\" class=\"jp-restore-screen\" tabindex=\"1\" title=\"restore screen\">restore screen</a></li>\r\n                            <li><a href=\"javascript:;\" class=\"jp-repeat\" tabindex=\"1\" title=\"repeat\">repeat</a></li>\r\n                            <li><a href=\"javascript:;\" class=\"jp-repeat-off\" tabindex=\"1\" title=\"repeat off\">repeat off</a></li>\r\n                        </ul>\r\n                    </div>\r\n                    <div class=\"jp-details\">\r\n                        <ul>\r\n                            <li>\r\n                                <span class=\"jp-title\"></span>\r\n                            </li>\r\n                        </ul>\r\n                    </div>\r\n                </div>\r\n            </div>\r\n            <div class=\"jp-no-solution\">\r\n                <span>Update Required</span>\r\n                To play the media you will need to either update your browser to a recent version or update your <a href=\"http://get.adobe.com/flashplayer/\" target=\"_blank\">Flash plugin</a>.\r\n            </div>\r\n        </div>\r\n    </div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/objects/video_control.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "";


  return buffer;
  });

this["JST"]["files/templates/objects/video_player.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div></div>";
  });

this["JST"]["files/templates/objects/video_source.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "";


  return buffer;
  });

this["JST"]["files/templates/plugins/clock.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression;


  buffer += "<span id=\"time\">";
  if (helper = helpers.hours) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.hours); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + ":";
  if (helper = helpers.minutes) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.minutes); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</span><span id=\"timeSuffix\">";
  if (helper = helpers.suffix) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.suffix); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</span>\r\n<br/>\r\n<span id=\"date\">";
  if (helper = helpers.weekAbr) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.weekAbr); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + ", ";
  if (helper = helpers.monthAbr) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.monthAbr); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + " ";
  if (helper = helpers.date) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.date); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</span>";
  return buffer;
  });

this["JST"]["files/templates/plugins/map-icon.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "";


  return buffer;
  });

this["JST"]["files/templates/plugins/map-view.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n            <li>\r\n                <button data-blast-id=\"";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" class=\"blast-btn\"><div class=\"btn-content\">";
  if (helper = helpers.name) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.name); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</div></button>\r\n            </li>\r\n            ";
  return buffer;
  }

function program3(depth0,data,depth1) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n        <div class=\"blast\" id=\"";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">\r\n            <div class=\"danger-zone\"  style=\"top:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.top)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;left:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.left)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;height:";
  if (helper = helpers.zone_dead_d) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_dead_d); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;width:";
  if (helper = helpers.zone_dead_d) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_dead_d); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;margin-top:-";
  if (helper = helpers.zone_dead_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_dead_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;margin-left:-";
  if (helper = helpers.zone_dead_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_dead_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;border-radius:";
  if (helper = helpers.zone_dead_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_dead_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;\"> </div>\r\n            <div class=\"warning-zone\" style=\"top:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.top)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;left:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.left)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;height:";
  if (helper = helpers.zone_warn_d) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_warn_d); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;width:";
  if (helper = helpers.zone_warn_d) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_warn_d); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;margin-top:-";
  if (helper = helpers.zone_warn_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_warn_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;margin-left:-";
  if (helper = helpers.zone_warn_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_warn_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;border-radius:";
  if (helper = helpers.zone_warn_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_warn_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;\"> </div>\r\n            <div class=\"safe-zone\"    style=\"top:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.top)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;left:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.left)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;height:";
  if (helper = helpers.zone_safe_d) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_safe_d); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;width:";
  if (helper = helpers.zone_safe_d) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_safe_d); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;margin-top:-";
  if (helper = helpers.zone_safe_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_safe_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;margin-left:-";
  if (helper = helpers.zone_safe_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_safe_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;border-radius:";
  if (helper = helpers.zone_safe_r) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.zone_safe_r); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;\"> </div>\r\n            <div class=\"dist-inner\"   style=\"top:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.top)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;left:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.left)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;margin-left:";
  if (helper = helpers.pos_inner) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.pos_inner); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;\">";
  if (helper = helpers.tag_inner) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.tag_inner); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</div>\r\n            <div class=\"dist-outer\"   style=\"top:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.top)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;left:"
    + escapeExpression(((stack1 = ((stack1 = (depth1 && depth1.position)),stack1 == null || stack1 === false ? stack1 : stack1.left)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;margin-left:";
  if (helper = helpers.pos_outer) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.pos_outer); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "px;\">";
  if (helper = helpers.tag_outer) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.tag_outer); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</div>\r\n        </div>\r\n        ";
  return buffer;
  }

  buffer += "<div class=\"map-outer\">\r\n    <div class=\"map-legend\">\r\n        <h1>IED Type</h1>\r\n        <ul>\r\n            ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.zone), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        </ul>\r\n    </div>\r\n    <div class=\"map-key\">\r\n        <h1>Key</h1>\r\n        <div class=\"item danger\">\r\n            <div class=\"item-box\"> </div>\r\n            <div class=\"item-text\">Mandatory Evacuation Distance</div>\r\n        </div>\r\n        <div class=\"item warning\">\r\n            <div class=\"item-box\"> </div>\r\n            <div class=\"item-text\">Shelter-in-Place Zone</div>\r\n        </div>\r\n        <div class=\"item safe\">\r\n            <div class=\"item-box\"> </div>\r\n            <div class=\"item-text\">Preferred Evacuation Distance</div>\r\n        </div>\r\n    </div>\r\n    <div class=\"map\">\r\n        <div class=\"blast-icon\" style=\"top:"
    + escapeExpression(((stack1 = ((stack1 = (depth0 && depth0.position)),stack1 == null || stack1 === false ? stack1 : stack1.top)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;left:"
    + escapeExpression(((stack1 = ((stack1 = (depth0 && depth0.position)),stack1 == null || stack1 === false ? stack1 : stack1.left)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "px;\"> </div>\r\n        ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.zone), {hash:{},inverse:self.noop,fn:self.programWithDepth(3, program3, data, depth0),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        <img src=\"";
  if (helper = helpers.image) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.image); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">\r\n    </div>\r\n    <div class=\"map-close\" style=\"\">Close Map</div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/plugins/playlist.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n    <li id=\"";
  if (helper = helpers.id) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.id); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" class=\"playlist-trigger\" data-trigger-event=\"";
  if (helper = helpers.event) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.event); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">";
  if (helper = helpers.name) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.name); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</li>\r\n    ";
  return buffer;
  }

  buffer += "<ul class=\"trigger-list\">\r\n    ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.triggers), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n</ul>\r\n<div class=\"title\">Video Play List</div>";
  return buffer;
  });

this["JST"]["files/templates/plugins/radio.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div class=\"radio\"></div>";
  });

this["JST"]["files/templates/plugins/review.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper, options;
  buffer += "\r\n        <tr>\r\n        ";
  stack1 = (helper = helpers.ifMatch || (depth0 && depth0.ifMatch),options={hash:{},inverse:self.program(4, program4, data),fn:self.program(2, program2, data),data:data},helper ? helper.call(depth0, (depth0 && depth0.state), "incomplete", options) : helperMissing.call(depth0, "ifMatch", (depth0 && depth0.state), "incomplete", options));
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        </tr>\r\n        ";
  return buffer;
  }
function program2(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n            <td>";
  if (helper = helpers.title) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.title); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</td>\r\n            <td></td>\r\n            <td></td>\r\n            <td></td>\r\n            <td class=\"adv-review-state ";
  if (helper = helpers.state) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.state); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">";
  if (helper = helpers.status) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.status); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</td>\r\n        ";
  return buffer;
  }

function program4(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n            <td>";
  if (helper = helpers.title) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.title); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</td>\r\n            <td>";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.stem), {hash:{},inverse:self.noop,fn:self.program(5, program5, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</td>\r\n            <td>\r\n                ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.selection), {hash:{},inverse:self.noop,fn:self.program(7, program7, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n                ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.selections), {hash:{},inverse:self.noop,fn:self.program(9, program9, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n            </td>\r\n            <td>";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.feedback), {hash:{},inverse:self.noop,fn:self.program(15, program15, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</td>\r\n            <td class=\"adv-review-state ";
  if (helper = helpers.state) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.state); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">";
  if (helper = helpers.status) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.status); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</td>\r\n        ";
  return buffer;
  }
function program5(depth0,data) {
  
  var stack1, helper;
  if (helper = helpers.stem) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.stem); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  return escapeExpression(stack1);
  }

function program7(depth0,data) {
  
  var stack1, helper;
  if (helper = helpers.selection) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.selection); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  return escapeExpression(stack1);
  }

function program9(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n                <p>This question was looking for ";
  if (helper = helpers.expected) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.expected); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + " selections.</p>\r\n                <ul>\r\n                ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.selections), {hash:{},inverse:self.noop,fn:self.program(10, program10, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "        \r\n                </ul>\r\n                ";
  return buffer;
  }
function program10(depth0,data) {
  
  var buffer = "", stack1;
  buffer += "\r\n                ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.isCorrect), {hash:{},inverse:self.program(13, program13, data),fn:self.program(11, program11, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n                ";
  return buffer;
  }
function program11(depth0,data) {
  
  var buffer = "", stack1;
  buffer += "<li>"
    + escapeExpression(((stack1 = (depth0 && depth0.text)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + " <span class=\"correct\">(Correct)</span></li>";
  return buffer;
  }

function program13(depth0,data) {
  
  var buffer = "", stack1;
  buffer += "<li>"
    + escapeExpression(((stack1 = (depth0 && depth0.text)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + " <span class=\"incorrect\">(Incorrect)</span></li>";
  return buffer;
  }

function program15(depth0,data) {
  
  var stack1, helper;
  if (helper = helpers.feedback) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.feedback); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  return escapeExpression(stack1);
  }

  buffer += "<div class=\"adv-review\">\r\n    <h1>";
  if (helper = helpers.percent) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.percent); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "% Complete</h1>\r\n    <table>\r\n        <tr>\r\n            <th>Item</th>\r\n            <th>Prompt</th>\r\n            <th>Selection</th>\r\n            <th>Feedback</th>\r\n            <th>Status</th>\r\n        </tr>\r\n        ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.results), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    </table>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/plugins/review.old.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper, options;
  buffer += "\r\n    ";
  stack1 = (helper = helpers.ifMatch || (depth0 && depth0.ifMatch),options={hash:{},inverse:self.program(4, program4, data),fn:self.program(2, program2, data),data:data},helper ? helper.call(depth0, (depth0 && depth0.state), "incomplete", options) : helperMissing.call(depth0, "ifMatch", (depth0 && depth0.state), "incomplete", options));
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    ";
  return buffer;
  }
function program2(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n    <h2>";
  if (helper = helpers.title) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.title); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</h2>\r\n    <div class=\"adv-review-state ";
  if (helper = helpers.state) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.state); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">";
  if (helper = helpers.status) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.status); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</div>\r\n    ";
  return buffer;
  }

function program4(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n    <h2>";
  if (helper = helpers.title) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.title); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</h2>\r\n    <div class=\"adv-review-state ";
  if (helper = helpers.state) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.state); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">";
  if (helper = helpers.status) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.status); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</div>\r\n    ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.stem), {hash:{},inverse:self.noop,fn:self.program(5, program5, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.selection), {hash:{},inverse:self.noop,fn:self.program(7, program7, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.selections), {hash:{},inverse:self.noop,fn:self.program(9, program9, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.feedback), {hash:{},inverse:self.noop,fn:self.program(15, program15, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n    ";
  return buffer;
  }
function program5(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n    <p><span class=\"underline bold\">Prompt:</span> ";
  if (helper = helpers.stem) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.stem); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</p>\r\n    ";
  return buffer;
  }

function program7(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n    <p><span class=\"underline bold\">Selection:</span> ";
  if (helper = helpers.selection) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.selection); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</p>\r\n    ";
  return buffer;
  }

function program9(depth0,data) {
  
  var buffer = "", stack1;
  buffer += "\r\n    <p><span class=\"underline bold\">Selections:</span></p>\r\n    <ul>\r\n    ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.selections), {hash:{},inverse:self.noop,fn:self.program(10, program10, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "        \r\n    </ul>\r\n    ";
  return buffer;
  }
function program10(depth0,data) {
  
  var buffer = "", stack1;
  buffer += "\r\n    <li class=\"";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.isCorrect), {hash:{},inverse:self.program(13, program13, data),fn:self.program(11, program11, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\">"
    + escapeExpression(((stack1 = (depth0 && depth0.text)),typeof stack1 === functionType ? stack1.apply(depth0) : stack1))
    + "</li>\r\n    ";
  return buffer;
  }
function program11(depth0,data) {
  
  
  return "correct";
  }

function program13(depth0,data) {
  
  
  return "incorrect";
  }

function program15(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n    <p><span class=\"underline bold\">Feedback:</span> ";
  if (helper = helpers.feedback) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.feedback); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "</p>\r\n    ";
  return buffer;
  }

  buffer += "<div class=\"adv-review\">\r\n    <h1>Actions Steps <span>";
  if (helper = helpers.percent) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.percent); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "% Complete</span></h1>\r\n    ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.results), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/plugins/status.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression;


  buffer += "<div class=\"status-clock-icon\"></div>\r\n<div class=\"status-timer-bar ";
  if (helper = helpers.status) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.status); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\">\r\n    <div class=\"bar\">\r\n        <div class=\"bar-time\"></div>\r\n    </div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/screens/aar.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div class=\"screen\">\r\n    <div class=\"layer menu-box\">\r\n    	<div class=\"menu-wrap\">\r\n            <div class=\"menu-tabs\" style=\"font-size: 23px; padding-top: 7px;\">AFTER ACTION REVIEW</div>\r\n            <div class=\"menu-content\"></div>\r\n            <div class=\"menu-footer\"></div>\r\n            <div class=\"menu-corner\"></div>\r\n        </div>\r\n        <div class=\"content-box\" style=\"overflow:auto;\">\r\n            <div id=\"aar\"></div>\r\n        </div>\r\n        <div class=\"menu-buttons wide\">\r\n            <button class=\"restart\"><div class=\"btn-content\">Restart</div></button>\r\n            <button class=\"menu\"><div class=\"btn-content\">Scenarios</div></button>         \r\n        </div>\r\n    </div>\r\n</div>";
  });

this["JST"]["files/templates/screens/godmode.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div id=\"god-menu\">\r\n    <ul>\r\n        <li><a href=\"#tabs-god-state\">Status</a></li>\r\n        <li><a href=\"#tabs-god-buttons\">Buttons</a></li>\r\n        <!--<li><a href=\"#tabs-god-clock\">Clock</a></li>\r\n        <li><a href=\"#tabs-god-space\">Transport</a></li>\r\n        -->\r\n    </ul>\r\n    <div id=\"tabs-god-state\">\r\n        <p>Game State: <span id=\"game-state\"></span></p>\r\n        <p>Scenario: <span id=\"fsm-game-state\"></span></p>\r\n        <p>FSM game-view: <span id=\"fsm-game-view\"></span></p>\r\n        <p>ADEN Time Game: <span class=\"aden-time-game\"></span></p>\r\n        <p>ADEN Time Elapsed: <span class=\"aden-time-elapsed\"></span></p>\r\n        <p>ADEN Time Ran: <span class=\"aden-time-ran\"></span></p>\r\n        <p>Viewport: <span class=\"aden-viewport\"></span></p>\r\n        <p>Docuement-Element: <span class=\"aden-document\"></span></p>\r\n        <p>Window: <span class=\"aden-window\"></span></p>\r\n        <!--<p>\r\n            Events:\r\n            <input id=\"eventSkip\" type=\"button\" value=\"Skip to next active timed event\" />\r\n        </p>-->\r\n    </div>\r\n    <div id=\"tabs-god-buttons\">\r\n        <button id=\"trigger-save-clear\"><div class=\"btn-content\">Clear Save Data</div></button>\r\n        <button id=\"trigger-set-complete\"><div class=\"btn-content\">Set All Complete</div></button>\r\n        <button id=\"trigger-get-view\"><div class=\"btn-content\">Get View Info</div></button>\r\n        <button id=\"trigger-video-pause\"><div class=\"btn-content\">Pause Video</div></button>\r\n        <button id=\"trigger-video-resume\"><div class=\"btn-content\">Resume Video</div></button>\r\n    </div>\r\n    <!--\r\n    <div id=\"tabs-god-clock\">\r\n        <p>\r\n            Time:\r\n            <input type=\"button\" value=\"Add 1 min\" onclick=\"aden.clock.addTime('00:01:00.00')\" />\r\n            <input type=\"button\" value=\"Add 10 min\" onclick=\"aden.clock.addTime('00:10:00.00')\" />\r\n            <input type=\"button\" value=\"Add 1 hour\" onclick=\"aden.clock.addTime('01:00:00.00')\" />\r\n            <input type=\"button\" value=\"Stop\" onclick=\"aden.clock.pause();\" /> \r\n            <input type=\"button\" value=\"Start\" onclick=\"aden.clock.start();\" /> \r\n        </p>\r\n        <p>\r\n            Speed:\r\n            <input type=\"button\" value=\"1x\" onclick=\"aden.clock.setSpeed(1)\" />\r\n            <input type=\"button\" value=\"2x\" onclick=\"aden.clock.setSpeed(2)\" />\r\n            <input type=\"button\" value=\"5x\" onclick=\"aden.clock.setSpeed(5)\" />\r\n            <input type=\"button\" value=\"10x\" onclick=\"aden.clock.setSpeed(10)\" />\r\n            <input type=\"button\" value=\"20x\" onclick=\"aden.clock.setSpeed(20)\" />\r\n            <input type=\"button\" value=\"30x\" onclick=\"aden.clock.setSpeed(30)\" />\r\n            <input type=\"button\" value=\"60x\" onclick=\"aden.clock.setSpeed(60)\" />\r\n            <input type=\"button\" value=\"90x\" onclick=\"aden.clock.setSpeed(90)\" />\r\n            <input type=\"button\" value=\"120x\" onclick=\"aden.clock.setSpeed(120)\" />\r\n            <input type=\"button\" value=\"240x\" onclick=\"aden.clock.setSpeed(240)\" />\r\n            <input type=\"button\" value=\"480x\" onclick=\"aden.clock.setSpeed(480)\" />\r\n        </p>\r\n    </div>\r\n    <div id=\"tabs-god-space\">\r\n        <p>\r\n            Locations:\r\n            <input type=\"button\" value=\"Front\"     onclick=\"aden.pano.load('frontnode01');\"    />\r\n            <input type=\"button\" value=\"Lobby 01\"  onclick=\"aden.pano.load('lobbynode01');\"    />\r\n            <input type=\"button\" value=\"Lobby 02\"  onclick=\"aden.pano.load('lobbynode02');\"    />\r\n            <input type=\"button\" value=\"Lobby 03\"  onclick=\"aden.pano.load('lobbynode03');\"    />\r\n            <input type=\"button\" value=\"Lobby 04\"  onclick=\"aden.pano.load('lobbynode04');\"    />\r\n            <input type=\"button\" value=\"Office 01\" onclick=\"aden.pano.load('officenode01');\"   />\r\n            <input type=\"button\" value=\"Office 02\" onclick=\"aden.pano.load('officenode02');\"   />\r\n            <input type=\"button\" value=\"Office 03\" onclick=\"aden.pano.load('officenode03');\"   />\r\n            <input type=\"button\" value=\"Bay 01\"    onclick=\"aden.pano.load('upperbaynode01');\" />\r\n            <input type=\"button\" value=\"Bay 02\"    onclick=\"aden.pano.load('upperbaynode02');\" />\r\n            <input type=\"button\" value=\"Bay 03\"    onclick=\"aden.pano.load('upperbaynode03');\" />\r\n            <input type=\"button\" value=\"Bay 04\"    onclick=\"aden.pano.load('upperbaynode04');\" />\r\n            <input type=\"button\" value=\"Bay 05\"    onclick=\"aden.pano.load('upperbaynode05');\" />\r\n            <input type=\"button\" value=\"Bay 06\"    onclick=\"aden.pano.load('upperbaynode06');\" />\r\n            <input type=\"button\" value=\"Bay 07\"    onclick=\"aden.pano.load('upperbaynode07');\" />\r\n        </p>\r\n    </div>\r\n    <div id=\"tabs-god-other\">\r\n        <p>\r\n            Add Overlays\r\n            <input type=\"button\" value=\"bay1\"   onclick=\"Actions.overlays.add('car1');\" />\r\n            <input type=\"button\" value=\"bay2\"   onclick=\"Actions.overlays.add('car2');\" />\r\n            <input type=\"button\" value=\"bay3\"   onclick=\"Actions.overlays.add('car3');\" />\r\n            <input type=\"button\" value=\"coffee\" onclick=\"Actions.overlays.add('coffee');\" /> \r\n        </p>\r\n        <p>\r\n            Hide Overlays\r\n            <input type=\"button\" value=\"bay1\"   onclick=\"Actions.overlays.remove('car1');\" />\r\n            <input type=\"button\" value=\"bay2\"   onclick=\"Actions.overlays.remove('car2');\" />\r\n            <input type=\"button\" value=\"bay3\"   onclick=\"Actions.overlays.remove('car3');\" />\r\n            <input type=\"button\" value=\"coffee\" onclick=\"Actions.overlays.remove('coffee');\" /> \r\n        </p>\r\n    </div>\r\n    -->\r\n</div>";
  });

this["JST"]["files/templates/screens/instructions.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  
  return "fit-text";
  }

function program3(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n        	<div class=\"square-fit-height image-right\">\r\n        		<div class=\"image-box\">\r\n        		    <div class=\"image\" style=\"background: white;\"><img src=\"";
  if (helper = helpers.img) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.img); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" alt=\"\" /></div>\r\n        		    <div class=\"corner-tr\"></div>\r\n        		    <div class=\"corner-br\"></div>\r\n        		    <div class=\"corner-bl\"></div>\r\n        		</div>\r\n        	</div>\r\n        	";
  return buffer;
  }

  buffer += "<div class=\"screen\">\r\n    <img src=\"files/assets/images/fills/gradient.png\" class=\"bg\"/>\r\n    <img src=\"files/assets/images/gui/title.png\" class=\"title\" />\r\n    <div class=\"layer menu-box\">\r\n    	<div class=\"menu-wrap\">\r\n            <div class=\"menu-content\"></div>\r\n            <div class=\"menu-footer\"></div>\r\n            <div class=\"menu-corner\"></div>\r\n        </div>\r\n        <div class=\"content-box\">\r\n        	<div class=\"menu-textbox ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.img), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\">\r\n        	    ";
  if (helper = helpers.text) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.text); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        	</div>\r\n        	";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.img), {hash:{},inverse:self.noop,fn:self.program(3, program3, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        </div>\r\n        <div class=\"menu-buttons\">\r\n            <button class=\"back\"><div class=\"btn-content\">Back</div></button>         \r\n            <button class=\"next\"><div class=\"btn-content\">Next</div></button>\r\n        </div>\r\n    </div>\r\n	<div class=\"fuou fuou-top\">FOR OFFICIAL USE ONLY</div>\r\n	<div class=\"fuou fuou-bottom\">FOR OFFICIAL USE ONLY</div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/screens/introduction.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression;


  buffer += "<div class=\"screen\">\r\n    <img src=\"files/assets/images/fills/gradient.png\" class=\"bg\"/>\r\n    <img src=\"files/assets/images/gui/title.png\" class=\"title\" />\r\n    <div class=\"layer menu-box\">\r\n    	<div class=\"menu-wrap\">\r\n            <div class=\"menu-tabs\" style=\"font-size: 23px; padding-top: 7px;\">FOR OFFICIAL USE ONLY</div>\r\n            <div class=\"menu-content\"></div>\r\n            <div class=\"menu-footer\"></div>\r\n            <div class=\"menu-corner\"></div>\r\n        </div>\r\n        <div class=\"content-box\">\r\n        	<div class=\"menu-textbox fit-text\">\r\n        	    ";
  if (helper = helpers.text) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.text); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        	</div>\r\n        	<div class=\"square-fit-height image-right\">\r\n        		<div class=\"image-box\">\r\n        		    <div class=\"image\" style=\"background: white;\"><img src=\"";
  if (helper = helpers.img) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.img); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" alt=\"\" /></div>\r\n        		    <div class=\"corner-tr\"></div>\r\n        		    <div class=\"corner-br\"></div>\r\n        		    <div class=\"corner-bl\"></div>\r\n        		</div>\r\n        	</div>\r\n        </div>\r\n        <div class=\"menu-buttons\">\r\n            <button class=\"back\"><div class=\"btn-content\">Back</div></button>     \r\n            <button class=\"next\"><div class=\"btn-content\">Next</div></button>\r\n        </div>\r\n    </div>\r\n	<div class=\"fuou fuou-top\">FOR OFFICIAL USE ONLY</div>\r\n	<div class=\"fuou fuou-bottom\">FOR OFFICIAL USE ONLY</div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/screens/pause.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div class=\"screen\">\r\n    <div class=\"menu-box layer\">\r\n        <div class=\"menu-wrap\">\r\n            <div class=\"menu-tabs\">\r\n                Resources\r\n            </div>\r\n            <div class=\"menu-content\"></div>\r\n            <div class=\"menu-footer\"></div>\r\n            <div class=\"menu-corner\"></div>\r\n        </div>\r\n        <div class=\"content-box\">\r\n        	<div class=\"menu-textbox fit-text\">\r\n        	    <div class=\"resources\">\r\n        	        <h1 id=\"\">Resources</h1>\r\n        	        <ul>\r\n        	            <li><a href=\"files/assets/pdf/IED_Merged_Resources.pdf\" target=\"_blank\">All Resources</a></li>\r\n        	        	<li><a href=\"files/assets/pdf/Bomb Threat Standoff Card.pdf\" target=\"_blank\">Bomb Threat Standoff Card</a></li>\r\n        	        	<li><a href=\"files/assets/pdf/First Responder Safety Card v5.pdf\" target=\"_blank\">First Responder Safety Card</a></li>\r\n        	            <li><a href=\"files/assets/pdf/Help.pdf\" target=\"_blank\">Help</a></li>\r\n        	            <li><a href=\"files/assets/pdf/IED_Components.pdf\" target=\"_blank\">IED Components</a></li>\r\n        	            <li><a href=\"files/assets/pdf/IED_Types_by_Function.pdf\" target=\"_blank\">IED Types by Function</a></li>\r\n        	            <li><a href=\"files/assets/pdf/IED_Acronym_List.pdf\" target=\"_blank\">Acronym List</a></li>\r\n        	            <li><a href=\"files/assets/pdf/DHS-DOJ Bomb Threat Guidance Brochure_FINAL (Jun 2013).pdf\" target=\"_blank\">DHS-DOJ Bomb Threat Guidance Brochure</a></li>\r\n        	            <li><a href=\"files/assets/pdf/VBIED Identification Guide - Parked Vehicles (rev 07-2013).pdf\" target=\"_blank\">VBIED Identification Guide - Parked Vehicles</a></li>\r\n        	        </ul>\r\n        	    </div>\r\n        	    <div class=\"scenarios\"style=\"display:none;\">\r\n        	        <h1 id=\"\">Scenarios</h1>\r\n        	    </div>\r\n        	</div>\r\n        	<div class=\"square-fit-height image-right\">\r\n        		<div class=\"image-box\">\r\n        		    <div class=\"image\" style=\"background: white;\"><img src=\"files/assets/images/screens/scenario_01/IntroImage.png\" alt=\"\" /></div>\r\n        		    <div class=\"corner-tr\"></div>\r\n        		    <div class=\"corner-br\"></div>\r\n        		    <div class=\"corner-bl\"></div>\r\n        		</div>\r\n        	</div>\r\n        </div>\r\n        <div class=\"menu-buttons\">\r\n            <button class=\"resume\"><div class=\"btn-content\">Resume</div></button>\r\n            <button class=\"stop\"><div class=\"btn-content\">Stop</div></button>\r\n        </div>\r\n        <div class=\"menu-side-title\" style=\"position: absolute; width: 1em; height: 360px; overflow: visible; top: 50%; font-size: 24px; letter-spacing: 30px; margin-top: -176px; right: 9px;\">R E S O U R C E S </div>\r\n    </div>\r\n</div>";
  });

this["JST"]["files/templates/screens/pause2.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  


  return "<div class=\"screen\">\r\n    <div class=\"box\">\r\n        <div class=\"title\">Scenario Paused</div>\r\n        <div class=\"menu-buttons\">\r\n            <button class=\"resume\"><div class=\"btn-content\">Resume</div></button>\r\n        </div>\r\n    </div>\r\n</div>";
  });

this["JST"]["files/templates/screens/scenarioTitle.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function", escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n        	    <p>Status: ";
  if (helper = helpers.score) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.score); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "% complete</p>\r\n        	    ";
  return buffer;
  }

function program3(depth0,data) {
  
  
  return "\r\n        	    <p>Status: Not attempted</p>\r\n                ";
  }

  buffer += "<div class=\"screen\">\r\n    <img src=\"files/assets/images/fills/gradient.png\" class=\"bg\"/>\r\n    <img src=\"files/assets/images/gui/title.png\" class=\"title\" />\r\n    <div class=\"layer menu-box\">\r\n        <div class=\"menu-wrap\">\r\n            <div class=\"menu-tabs\" style=\"font-size: 23px; padding-top: 7px;\">FOR OFFICIAL USE ONLY</div>\r\n            <div class=\"menu-content\"></div>\r\n            <div class=\"menu-footer\"></div>\r\n            <div class=\"menu-corner\"></div>\r\n        </div>\r\n        <div class=\"content-box\">\r\n        	<div class=\"menu-textbox fit-text\">\r\n        	    <h1>";
  if (helper = helpers.title) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.title); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</h1>\r\n        	    ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.attempted), {hash:{},inverse:self.program(3, program3, data),fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        	    ";
  if (helper = helpers.description) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.description); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        	</div>\r\n        	<div class=\"square-fit-height image-right\">\r\n        		<div class=\"image-box\">\r\n        		    <div class=\"image\" style=\"background: white;\"><img src=\"";
  if (helper = helpers.img) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.img); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" alt=\"\" /></div>\r\n        		    <div class=\"corner-tr\"></div>\r\n        		    <div class=\"corner-br\"></div>\r\n        		    <div class=\"corner-bl\"></div>\r\n        		</div>\r\n        	</div>\r\n        </div>\r\n        <div class=\"menu-buttons\">\r\n            <button class=\"back\"><div class=\"btn-content\">Back</div></button>        \r\n            <button class=\"start\"><div class=\"btn-content\">Start</div></button>\r\n        </div>\r\n    </div>\r\n	<div class=\"fuou fuou-top\">FOR OFFICIAL USE ONLY</div>\r\n	<div class=\"fuou fuou-bottom\">FOR OFFICIAL USE ONLY</div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/screens/selection.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, self=this, functionType="function", escapeExpression=this.escapeExpression;

function program1(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n        	            <button class=\"";
  if (helper = helpers.styles) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.styles); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1);
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.attempted), {hash:{},inverse:self.program(7, program7, data),fn:self.program(2, program2, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\" ";
  stack1 = helpers.unless.call(depth0, (depth0 && depth0.enabled), {hash:{},inverse:self.noop,fn:self.program(9, program9, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += ">\r\n                            <div class=\"btn-content\">";
  if (helper = helpers.name) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.name); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "<span class=\"icon\"></span></div>\r\n                        </button>\r\n        	            <!--<button class=\"";
  if (helper = helpers.styles) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.styles); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1);
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.complete), {hash:{},inverse:self.program(7, program7, data),fn:self.program(3, program3, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\" ";
  stack1 = helpers.unless.call(depth0, (depth0 && depth0.enabled), {hash:{},inverse:self.noop,fn:self.program(9, program9, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "><div class=\"btn-content\">";
  if (helper = helpers.name) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.name); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "<span class=\"icon\"></span></div></button>-->\r\n        	        ";
  return buffer;
  }
function program2(depth0,data) {
  
  var stack1;
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.complete), {hash:{},inverse:self.program(5, program5, data),fn:self.program(3, program3, data),data:data});
  if(stack1 || stack1 === 0) { return stack1; }
  else { return ''; }
  }
function program3(depth0,data) {
  
  
  return "complete";
  }

function program5(depth0,data) {
  
  
  return "failed";
  }

function program7(depth0,data) {
  
  
  return "incomplete";
  }

function program9(depth0,data) {
  
  
  return "disabled";
  }

function program11(depth0,data) {
  
  var buffer = "", stack1, helper;
  buffer += "\r\n        	        <button id=\"certificate\" class=\"";
  if (helper = helpers.styles) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.styles); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  buffer += escapeExpression(stack1)
    + "\" ";
  stack1 = helpers.unless.call(depth0, (depth0 && depth0.enabled), {hash:{},inverse:self.noop,fn:self.program(9, program9, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "><div class=\"btn-content\">Certificate</div></button>\r\n        	        ";
  return buffer;
  }

function program13(depth0,data) {
  
  
  return "<button class=\"help\"><div class=\"btn-content\">Help</div></button>";
  }

  buffer += "<div class=\"screen\">\r\n    <img src=\"files/assets/images/fills/gradient.png\" class=\"bg\"/>\r\n    <img src=\"files/assets/images/gui/title.png\" class=\"title\" />\r\n    <div class=\"menu-box layer\">\r\n    	<div class=\"menu-wrap\">\r\n            <div class=\"menu-content\"></div>\r\n            <div class=\"menu-footer\"></div>\r\n            <div class=\"menu-corner\"></div>\r\n        </div>\r\n        <div class=\"content-box\">\r\n        	<div class=\"square-fit-height image-right\">\r\n        		<div class=\"image-box\">\r\n        		    <div class=\"image\" style=\"background: white;\"><img src=\"files/assets/images/screens/scenario_01/IntroImage.png\" alt=\"\" /></div>\r\n        		    <div class=\"corner-tr\"></div>\r\n        		    <div class=\"corner-br\"></div>\r\n        		    <div class=\"corner-bl\"></div>\r\n        		</div>\r\n        	</div>\r\n        	<div class=\"menu-textbox fit-text\">\r\n        	    <h1>Scenario Menu</h1>\r\n        	    <div class=\"menu-selections\">\r\n        	        ";
  stack1 = helpers.each.call(depth0, (depth0 && depth0.selections), {hash:{},inverse:self.noop,fn:self.program(1, program1, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        	        ";
  stack1 = helpers['with'].call(depth0, (depth0 && depth0.certificate), {hash:{},inverse:self.noop,fn:self.program(11, program11, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n        	    </div>\r\n        	</div>\r\n        </div>\r\n        <div class=\"menu-buttons\">\r\n            <button class=\"back\"><div class=\"btn-content\">Back</div></button>   \r\n            ";
  stack1 = helpers['if'].call(depth0, (depth0 && depth0.enableHelpBtn), {hash:{},inverse:self.noop,fn:self.program(13, program13, data),data:data});
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "\r\n            <button class=\"clear\"><div class=\"btn-content\">Restart</div></button>\r\n        </div>\r\n    </div>\r\n	<div class=\"fuou fuou-top\">FOR OFFICIAL USE ONLY</div>\r\n	<div class=\"fuou fuou-bottom\">FOR OFFICIAL USE ONLY</div>\r\n</div>";
  return buffer;
  });

this["JST"]["files/templates/screens/splash.html"] = Handlebars.template(function (Handlebars,depth0,helpers,partials,data) {
  this.compilerInfo = [4,'>= 1.0.0'];
helpers = this.merge(helpers, Handlebars.helpers); data = data || {};
  var buffer = "", stack1, helper, functionType="function";


  buffer += "<div class=\"screen\">\r\n    <div class=\"layer menu-box\">\r\n        <div class=\"menu-wrap\">\r\n            <div class=\"menu-content\"></div>\r\n            <div class=\"menu-footer\"></div>\r\n            <div class=\"menu-corner\"></div>\r\n        </div>\r\n		<div class=\"content-box\">\r\n			<div class=\"menu-textbox\">\r\n				<p>";
  if (helper = helpers.description) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.description); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</p>\r\n			</div>\r\n		</div>\r\n    	<div class=\"menu-buttons\">\r\n    		<button id=\"skip-intro\"><div class=\"btn-content\">Skip</div></button>   	    \r\n    		<button id=\"start-game\"><div class=\"btn-content\">Start</div></button>\r\n    	</div>\r\n    	<!--<div class=\"version\"><a href=\"release-notes.html\" target=\"_blank\">Version ";
  if (helper = helpers.version) { stack1 = helper.call(depth0, {hash:{},data:data}); }
  else { helper = (depth0 && depth0.version); stack1 = typeof helper === functionType ? helper.call(depth0, {hash:{},data:data}) : helper; }
  if(stack1 || stack1 === 0) { buffer += stack1; }
  buffer += "</a></div>-->\r\n    </div>\r\n	<div class=\"fuou fuou-top\">FOR OFFICIAL USE ONLY</div>\r\n	<div class=\"fuou fuou-bottom\">FOR OFFICIAL USE ONLY</div>\r\n</div>";
  return buffer;
  });

return this["JST"];

});