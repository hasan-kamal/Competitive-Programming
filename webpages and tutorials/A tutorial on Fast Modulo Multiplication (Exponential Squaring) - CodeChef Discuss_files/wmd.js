jQuery.extend({createUploadIframe:function(e,t){var n="jUploadFrame"+e;if(window.ActiveXObject){var a=document.createElement('<iframe id="'+n+'" name="'+n+'" />');if(typeof t=="boolean"){a.src="javascript:false"}else{if(typeof t=="string"){a.src=t}}}else{var a=document.createElement("iframe");a.id=n;a.name=n}a.style.position="absolute";a.style.top="-1000px";a.style.left="-1000px";document.body.appendChild(a);return a},createUploadForm:function(e,t){var n="jUploadForm"+e;var a="jUploadFile"+e;var r=$('<form  action="" method="POST" name="'+n+'" id="'+n+'" enctype="multipart/form-data"></form>');var i=$("#"+t);var o=$(i).clone();$(i).attr("id",a);$(i).before(o);$(i).appendTo(r);$(r).css("position","absolute");$(r).css("top","-1200px");$(r).css("left","-1200px");$(r).appendTo("body");return r},ajaxFileUpload:function(e){e=jQuery.extend({},jQuery.ajaxSettings,e);var t=(new Date).getTime();var n=jQuery.createUploadForm(t,e.fileElementId);var a=jQuery.createUploadIframe(t,e.secureuri);var r="jUploadFrame"+t;var i="jUploadForm"+t;if(e.global&&!jQuery.active++){jQuery.event.trigger("ajaxStart")}var o=false;var l={};if(e.global){jQuery.event.trigger("ajaxSend",[l,e])}var s=function(t){var a=document.getElementById(r);try{if(a.contentWindow){l.responseText=a.contentWindow.document.body?a.contentWindow.document.body.innerText:null;l.responseXML=a.contentWindow.document.XMLDocument?a.contentWindow.document.XMLDocument:a.contentWindow.document}else{if(a.contentDocument){l.responseText=a.contentDocument.document.body?a.contentDocument.document.body.textContent||document.body.innerText:null;l.responseXML=a.contentDocument.document.XMLDocument?a.contentDocument.document.XMLDocument:a.contentDocument.document}}}catch(i){jQuery.handleError(e,l,null,i)}if(l||t=="timeout"){o=true;var s;try{s=t!="timeout"?"success":"error";if(s!="error"){var c=jQuery.uploadHttpData(l,e.dataType);if(e.success){e.success(c,s)}if(e.global){jQuery.event.trigger("ajaxSuccess",[l,e])}}else{jQuery.handleError(e,l,s)}}catch(i){s="error";jQuery.handleError(e,l,s,i)}if(e.global){jQuery.event.trigger("ajaxComplete",[l,e])}if(e.global&&!--jQuery.active){jQuery.event.trigger("ajaxStop")}if(e.complete){e.complete(l,s)}jQuery(a).unbind();setTimeout(function(){try{$(a).remove();$(n).remove()}catch(t){jQuery.handleError(e,l,null,t)}},100);l=null}};if(e.timeout>0){setTimeout(function(){if(!o){s("timeout")}},e.timeout)}try{var n=$("#"+i);$(n).attr("action",e.url);$(n).attr("method","POST");$(n).attr("target",r);if(n.encoding){n.encoding="multipart/form-data"}else{n.enctype="multipart/form-data"}$(n).submit()}catch(c){jQuery.handleError(e,l,null,c)}if(window.attachEvent){document.getElementById(r).attachEvent("onload",s)}else{document.getElementById(r).addEventListener("load",s,false)}return{abort:function(){}}},uploadHttpData:function(r,type){var data=!type;data=type=="xml"||data?r.responseXML:r.responseText;if(type=="script"){jQuery.globalEval(data)}if(type=="json"){eval("data = "+data)}if(type=="html"){jQuery("<div>").html(data).evalScripts()}return data}});function ajaxFileUpload(e){$("#loading").ajaxStart(function(){$(this).show()}).ajaxComplete(function(){$(this).hide()});$("#upload").ajaxStart(function(){$(this).hide()}).ajaxComplete(function(){$(this).show()});$.ajaxFileUpload({url:scriptUrl+"upload/",secureuri:false,fileElementId:"file-upload",dataType:"xml",success:function(t,n){var a=$(t).find("file_url").text();var r=$(t).find("error").text();if(r!=""){alert(r)}else{e.attr("value",appUrl+a)}},error:function(e,t,n){alert(n)}});return false}var Attacklab=Attacklab||{};Attacklab.wmdBase=function(){var e=top.Attacklab;var t=top.document;var n=top.RegExp;var a=top.navigator;e.Util={};e.Position={};e.Command={};e.Global={};var r=e.Util;var i=e.Position;var o=e.Command;var l=e.Global;l.isIE=/msie/.test(a.userAgent.toLowerCase());l.isIE_5or6=/msie 6/.test(a.userAgent.toLowerCase())||/msie 5/.test(a.userAgent.toLowerCase());l.isIE_7plus=l.isIE&&!l.isIE_5or6;l.isOpera=/opera/.test(a.userAgent.toLowerCase());l.isKonqueror=/konqueror/.test(a.userAgent.toLowerCase());var s="<p style='margin-top: 0px'>"+$.i18n._("enter image url")+"</p>";var c="<p style='margin-top: 0px'>"+$.i18n._("enter url")+"</p>";var d="<div>"+$.i18n._("upload image")+"</div>"+'<input type="file" name="file-upload" id="file-upload" size="26" '+"onchange=\"return ajaxFileUpload($('#image-url'));\"/><br>"+'<img id="loading" src="'+mediaUrl("media/images/indicator.gif")+'" style="display:none;"/>';var u="http://";var f="http://";var p="images/";var m=500;var v=100;var h="http://wmd-editor.com/";var g="WMD website";var y="_blank";e.PanelCollection=function(){this.buttonBar=t.getElementById("wmd-button-bar");this.preview=t.getElementById("previewer");this.output=t.getElementById("wmd-output");this.input=t.getElementById("editor")};e.panels=undefined;e.ieCachedRange=null;e.ieRetardedClick=false;r.isVisible=function(e){if(window.getComputedStyle){return window.getComputedStyle(e,null).getPropertyValue("display")!=="none"}else if(e.currentStyle){return e.currentStyle["display"]!=="none"}};r.addEvent=function(e,t,n){if(e.attachEvent){e.attachEvent("on"+t,n)}else{e.addEventListener(t,n,false)}};r.removeEvent=function(e,t,n){if(e.detachEvent){e.detachEvent("on"+t,n)}else{e.removeEventListener(t,n,false)}};r.fixEolChars=function(e){e=e.replace(/\r\n/g,"\n");e=e.replace(/\r/g,"\n");return e};r.extendRegExp=function(e,t,n){if(t===null||t===undefined){t=""}if(n===null||n===undefined){n=""}var a=e.toString();var r="";var i=a.match(/\/([gim]*)$/);if(i===null){r=i[0]}else{r=""}a=a.replace(/(^\/|\/[gim]*$)/g,"");a=t+a+n;return new RegExp(a,r)};r.createImage=function(e){var n=p+e;var a=t.createElement("img");a.className="wmd-button";a.src=n;return a};r.prompt=function(e,n,o){var s;var c;var u;var f=0;if(arguments.length==4){f=arguments[3]}if(n===undefined){n=""}var p=function(e){var t=e.charCode||e.keyCode;if(t===27){m(true)}};var m=function(e){r.removeEvent(t.body,"keydown",p);var n=u.value;if(e){n=null}else{n=n.replace("http://http://","http://");n=n.replace("http://https://","https://");n=n.replace("http://ftp://","ftp://");if(n.indexOf("http://")===-1&&n.indexOf("ftp://")===-1&&n.indexOf("https://")===-1){n="http://"+n}}s.parentNode.removeChild(s);c.parentNode.removeChild(c);o(n);return false};var v=function(){c=t.createElement("div");c.className="wmd-prompt-background";style=c.style;style.position="absolute";style.top="0";style.zIndex="1000";if(l.isKonqueror){style.backgroundColor="transparent"}else if(l.isIE){style.filter="alpha(opacity=50)"}else{style.opacity="0.5"}var e=i.getPageSize();style.height=e[1]+"px";if(l.isIE){style.left=t.documentElement.scrollLeft;style.width=t.documentElement.clientWidth}else{style.left="0";style.width="100%"}t.body.appendChild(c)};var h=function(){s=t.createElement("div");s.className="wmd-prompt-dialog";s.style.padding="10px;";s.style.position="fixed";s.style.width="400px";s.style.zIndex="1001";var o=t.createElement("div");o.innerHTML=e;o.style.padding="5px";s.appendChild(o);var c=t.createElement("form");c.onsubmit=function(){return m(false)};style=c.style;style.padding="0";style.margin="0";style.cssFloat="left";style.width="100%";style.textAlign="center";style.position="relative";s.appendChild(c);u=t.createElement("input");u.id="image-url";u.type="text";u.value=n;style=u.style;style.display="block";style.width="80%";style.marginLeft=style.marginRight="auto";c.appendChild(u);var f=t.createElement("div");f.innerHTML=d;f.style.padding="5px";c.appendChild(f);var v=t.createElement("input");v.type="button";v.onclick=function(){return m(false)};v.value="OK";style=v.style;style.margin="10px";style.display="inline";style.width="7em";var h=t.createElement("input");h.type="button";h.onclick=function(){return m(true)};h.value="Cancel";style=h.style;style.margin="10px";style.display="inline";style.width="7em";if(/mac/.test(a.platform.toLowerCase())){c.appendChild(h);c.appendChild(v)}else{c.appendChild(v);c.appendChild(h)}r.addEvent(t.body,"keydown",p);s.style.top="50%";s.style.left="50%";s.style.display="block";if(l.isIE_5or6){s.style.position="absolute";s.style.top=t.documentElement.scrollTop+200+"px";s.style.left="50%"}t.body.appendChild(s);s.style.marginTop=-(i.getHeight(s)/2)+"px";s.style.marginLeft=-(i.getWidth(s)/2)+"px"};v();top.setTimeout(function(){h();var e=n.length;if(u.selectionStart!==undefined){u.selectionStart=0;u.selectionEnd=e}else if(u.createTextRange){var t=u.createTextRange();t.collapse(false);t.moveStart("character",-e);t.moveEnd("character",e);t.select()}u.focus()},0)};i.getTop=function(e,t){var n=e.offsetTop;if(!t){while(e=e.offsetParent){n+=e.offsetTop}}return n};i.getHeight=function(e){return e.offsetHeight||e.scrollHeight};i.getWidth=function(e){return e.offsetWidth||e.scrollWidth};i.getPageSize=function(){var e,n;var a,r;if(self.innerHeight&&self.scrollMaxY){e=t.body.scrollWidth;n=self.innerHeight+self.scrollMaxY}else if(t.body.scrollHeight>t.body.offsetHeight){e=t.body.scrollWidth;n=t.body.scrollHeight}else{e=t.body.offsetWidth;n=t.body.offsetHeight}if(self.innerHeight){a=self.innerWidth;r=self.innerHeight}else if(t.documentElement&&t.documentElement.clientHeight){a=t.documentElement.clientWidth;r=t.documentElement.clientHeight}else if(t.body){a=t.body.clientWidth;r=t.body.clientHeight}var i=Math.max(e,a);var o=Math.max(n,r);return[i,o,a,r]};e.inputPoller=function(t,n){var a=this;var i=e.panels.input;var o;var l;var s;var c;this.tick=function(){if(!r.isVisible(i)){return}if(i.selectionStart||i.selectionStart===0){var e=i.selectionStart;var t=i.selectionEnd;if(e!=o||t!=l){o=e;l=t;if(s!=i.value){s=i.value;return true}}}return false};var d=function(){if(!r.isVisible(i)){return}if(a.tick()){t()}};var u=function(){c=top.setInterval(d,n)};this.destroy=function(){top.clearInterval(c)};u()};e.undoManager=function(t){var n=this;var a=[];var i=0;var o="none";var s;var c;var d;var u;var f=function(e,t){if(o!=e){o=e;if(!t){m()}}if(!l.isIE||o!="moving"){d=top.setTimeout(p,1)}else{u=null}};var p=function(){u=new e.TextareaState;c.tick();d=undefined};this.setCommandMode=function(){o="command";m();d=top.setTimeout(p,0)};this.canUndo=function(){return i>1};this.canRedo=function(){if(a[i+1]){return true}return false};this.undo=function(){if(n.canUndo()){if(s){s.restore();s=null}else{a[i]=new e.TextareaState;a[--i].restore();if(t){t()}}}o="none";e.panels.input.focus();p()};this.redo=function(){if(n.canRedo()){a[++i].restore();if(t){t()}}o="none";e.panels.input.focus();p()};var m=function(){var n=u||new e.TextareaState;if(!n){return false}if(o=="moving"){if(!s){s=n}return}if(s){if(a[i-1].text!=s.text){a[i++]=s}s=null}a[i++]=n;a[i+1]=null;if(t){t()}};var h=function(e){var t=false;if(e.ctrlKey||e.metaKey){var a=e.charCode||e.keyCode;var r=String.fromCharCode(a);switch(r){case"y":n.redo();t=true;break;case"z":if(!e.shiftKey){n.undo()}else{n.redo()}t=true;break}}if(t){if(e.preventDefault){e.preventDefault()}if(top.event){top.event.returnValue=false}return}};var g=function(e){if(!e.ctrlKey&&!e.metaKey){var t=e.keyCode;if(t>=33&&t<=40||t>=63232&&t<=63235){f("moving")}else if(t==8||t==46||t==127){f("deleting")}else if(t==13){f("newlines")}else if(t==27){f("escape")}else if((t<16||t>20)&&t!=91){f("typing")}}};var y=function(){r.addEvent(e.panels.input,"keypress",function(e){if((e.ctrlKey||e.metaKey)&&(e.keyCode==89||e.keyCode==90)){e.preventDefault()}});var t=function(){if(l.isIE||u&&u.text!=e.panels.input.value){if(d==undefined){o="paste";m();p()}}};c=new e.inputPoller(t,v);r.addEvent(e.panels.input,"keydown",h);r.addEvent(e.panels.input,"keydown",g);r.addEvent(e.panels.input,"mousedown",function(){f("moving")});e.panels.input.onpaste=t;e.panels.input.ondrop=t};var b=function(){y();p();m()};this.destroy=function(){if(c){c.destroy()}};b()};e.editor=function(n){if(!n){n=function(){}}var i=e.panels.input;var s=0;var c=this;var d;var u;var f;var p;var m;var v=function(t){i.focus();if(t.textOp){if(m){m.setCommandMode()}var a=new e.TextareaState;if(!a){return}var r=a.getChunks();var o=function(){i.focus();if(r){a.setChunks(r)}a.restore();n()};var l=true;var s=t.textOp(r,o,l);if(!s){o()}}if(t.execute){t.execute(c)}};var b=function(){if(m){w(document.getElementById("wmd-undo-button"),m.canUndo());w(document.getElementById("wmd-redo-button"),m.canRedo())}};var w=function(t,n){var a="0px";var r="-20px";var i="-40px";if(n){t.style.backgroundPosition=t.XShift+" "+a;t.onmouseover=function(){this.style.backgroundPosition=this.XShift+" "+i};t.onmouseout=function(){this.style.backgroundPosition=this.XShift+" "+a};if(l.isIE){t.onmousedown=function(){e.ieRetardedClick=true;e.ieCachedRange=document.selection.createRange()}}if(!t.isHelp){t.onclick=function(){if(this.onmouseout){this.onmouseout()}v(this);return false}}}else{t.style.backgroundPosition=t.XShift+" "+r;t.onmouseover=t.onmouseout=t.onclick=function(){}}};var x=function(){var e=document.getElementById("wmd-button-bar");var t="0px";var n="-20px";var r="-40px";var i=document.createElement("ul");i.id="wmd-button-row";i=e.appendChild(i);var l=document.createElement("li");l.className="wmd-button";l.id="wmd-bold-button";l.title="Strong <strong> Ctrl+B";l.XShift="0px";l.textOp=o.doBold;w(l,true);i.appendChild(l);var s=document.createElement("li");s.className="wmd-button";s.id="wmd-italic-button";s.title="Emphasis <em> Ctrl+I";s.XShift="-20px";s.textOp=o.doItalic;w(s,true);i.appendChild(s);var c=document.createElement("li");c.className="wmd-spacer";c.id="wmd-spacer1";i.appendChild(c);var d=document.createElement("li");d.className="wmd-button";d.id="wmd-link-button";d.title="Hyperlink <a> Ctrl+L";d.XShift="-40px";d.textOp=function(e,t,n){return o.doLinkOrImage(e,t,false)};w(d,true);i.appendChild(d);var u=document.createElement("li");u.className="wmd-button";u.id="wmd-quote-button";u.title="Blockquote <blockquote> Ctrl+Q";u.XShift="-60px";u.textOp=o.doBlockquote;w(u,true);i.appendChild(u);var f=document.createElement("li");f.className="wmd-button";f.id="wmd-code-button";f.title="Code Sample <pre><code> Ctrl+K";f.XShift="-80px";f.textOp=o.doCode;w(f,true);i.appendChild(f);var p=document.createElement("li");p.className="wmd-button";p.id="wmd-image-button";p.title="Image <img> Ctrl+G";p.XShift="-100px";p.textOp=function(e,t,n){return o.doLinkOrImage(e,t,true)};w(p,true);i.appendChild(p);var m=document.createElement("li");m.className="wmd-spacer";m.id="wmd-spacer2";i.appendChild(m);var v=document.createElement("li");v.className="wmd-button";v.id="wmd-olist-button";v.title="Numbered List <ol> Ctrl+O";v.XShift="-120px";v.textOp=function(e,t,n){o.doList(e,t,true,n)};w(v,true);i.appendChild(v);var x=document.createElement("li");x.className="wmd-button";x.id="wmd-ulist-button";x.title="Bulleted List <ul> Ctrl+U";x.XShift="-140px";x.textOp=function(e,t,n){o.doList(e,t,false,n)};w(x,true);i.appendChild(x);var T=document.createElement("li");T.className="wmd-button";T.id="wmd-heading-button";T.title="Heading <h1>/<h2> Ctrl+H";T.XShift="-160px";T.textOp=o.doHeading;w(T,true);i.appendChild(T);var E=document.createElement("li");E.className="wmd-button";E.id="wmd-hr-button";E.title="Horizontal Rule <hr> Ctrl+R";E.XShift="-180px";E.textOp=o.doHorizontalRule;w(E,true);i.appendChild(E);var k=document.createElement("li");k.className="wmd-spacer";k.id="wmd-spacer3";i.appendChild(k);var C=document.createElement("li");C.className="wmd-button";C.id="wmd-undo-button";C.title="Undo - Ctrl+Z";C.XShift="-200px";C.execute=function(e){e.undo()};w(C,true);i.appendChild(C);var $=document.createElement("li");$.className="wmd-button";$.id="wmd-redo-button";$.title="Redo - Ctrl+Y";if(/win/.test(a.platform.toLowerCase())){$.title="Redo - Ctrl+Y"}else{$.title="Redo - Ctrl+Shift+Z"}$.XShift="-220px";$.execute=function(e){e.redo()};w($,true);i.appendChild($);var S=document.createElement("li");S.className="wmd-button";S.id="wmd-help-button";S.XShift="-240px";S.isHelp=true;var I=document.createElement("a");I.href=h;I.target=y;I.title=g;S.appendChild(I);w(S,true);i.appendChild(S);b()};var T=function(){if(/\?noundo/.test(t.location.href)){e.nativeUndo=true}if(!e.nativeUndo){m=new e.undoManager(function(){n();b()})}x();var a="keydown";if(l.isOpera){a="keypress"}r.addEvent(i,a,function(e){if(e.ctrlKey||e.metaKey){var t=e.charCode||e.keyCode;var n=String.fromCharCode(t).toLowerCase();switch(n){case"b":v(document.getElementById("wmd-bold-button"));break;case"i":v(document.getElementById("wmd-italic-button"));break;case"l":v(document.getElementById("wmd-link-button"));break;case"q":v(document.getElementById("wmd-quote-button"));break;case"k":v(document.getElementById("wmd-code-button"));break;case"g":v(document.getElementById("wmd-image-button"));break;case"o":v(document.getElementById("wmd-olist-button"));break;case"u":v(document.getElementById("wmd-ulist-button"));break;case"h":v(document.getElementById("wmd-heading-button"));break;case"r":v(document.getElementById("wmd-hr-button"));break;case"y":v(document.getElementById("wmd-redo-button"));break;case"z":if(e.shiftKey){v(document.getElementById("wmd-redo-button"))}else{v(document.getElementById("wmd-undo-button"))}break;default:return}if(e.preventDefault){e.preventDefault()}if(top.event){top.event.returnValue=false}}});r.addEvent(i,"keyup",function(e){if(!e.shiftKey&&!e.ctrlKey&&!e.metaKey){var t=e.charCode||e.keyCode;if(t===13){fakeButton={};fakeButton.textOp=o.doAutoindent;v(fakeButton)}}});if(l.isIE){r.addEvent(i,"keydown",function(e){var t=e.keyCode;if(t===27){return false}})}if(i.form){var s=i.form.onsubmit;i.form.onsubmit=function(){E();if(s){return s.apply(this,arguments)}}}};var E=function(){if(e.showdown){var t=new e.showdown.converter}var n=i.value;var a=function(){i.value=n};if(!/markdown/.test(e.wmd_env.output.toLowerCase())){if(t){i.value=t.makeHtml(n);top.setTimeout(a,0)}}return true};this.undo=function(){if(m){m.undo()}};this.redo=function(){if(m){m.redo()}};var k=function(){T()};this.destroy=function(){if(m){m.destroy()}if(f.parentNode){f.parentNode.removeChild(f)}if(i){i.style.marginTop=""}top.clearInterval(p)};k()};e.TextareaState=function(){var n=this;var a=e.panels.input;this.init=function(){if(!r.isVisible(a)){return}this.setInputAreaSelectionStartEnd();this.scrollTop=a.scrollTop;if(!this.text&&a.selectionStart||a.selectionStart===0){this.text=a.value}};this.setInputAreaSelection=function(){if(!r.isVisible(a)){return}if(a.selectionStart!==undefined&&!l.isOpera){a.focus();a.selectionStart=n.start;a.selectionEnd=n.end;a.scrollTop=n.scrollTop}else if(t.selection){if(t.activeElement&&t.activeElement!==a){return}a.focus();var e=a.createTextRange();e.moveStart("character",-a.value.length);e.moveEnd("character",-a.value.length);e.moveEnd("character",n.end);e.moveStart("character",n.start);e.select()}};this.setInputAreaSelectionStartEnd=function(){if(a.selectionStart||a.selectionStart===0){n.start=a.selectionStart;n.end=a.selectionEnd}else if(t.selection){n.text=r.fixEolChars(a.value);var i;if(e.ieRetardedClick&&e.ieCachedRange){i=e.ieCachedRange;e.ieRetardedClick=false}else{i=t.selection.createRange()}var o=r.fixEolChars(i.text);var l="";var s=l+o+l;i.text=s;var c=r.fixEolChars(a.value);i.moveStart("character",-s.length);i.text=o;n.start=c.indexOf(l);n.end=c.lastIndexOf(l)-l.length;var d=n.text.length-r.fixEolChars(a.value).length;if(d){i.moveStart("character",-o.length);while(d--){o+="\n";n.end+=1}i.text=o}this.setInputAreaSelection()}};this.restore=function(){if(n.text!=undefined&&n.text!=a.value){a.value=n.text}this.setInputAreaSelection();a.scrollTop=n.scrollTop};this.getChunks=function(){var t=new e.Chunks;t.before=r.fixEolChars(n.text.substring(0,n.start));t.startTag="";t.selection=r.fixEolChars(n.text.substring(n.start,n.end));t.endTag="";t.after=r.fixEolChars(n.text.substring(n.end));t.scrollTop=n.scrollTop;return t};this.setChunks=function(e){e.before=e.before+e.startTag;e.after=e.endTag+e.after;if(l.isOpera){e.before=e.before.replace(/\n/g,"\r\n");e.selection=e.selection.replace(/\n/g,"\r\n");e.after=e.after.replace(/\n/g,"\r\n")}this.start=e.before.length;this.end=e.before.length+e.selection.length;this.text=e.before+e.selection+e.after;this.scrollTop=e.scrollTop};this.init()};e.Chunks=function(){};e.Chunks.prototype.findTags=function(e,t){var n=this;var a;if(e){a=r.extendRegExp(e,"","$");this.before=this.before.replace(a,function(e){n.startTag=n.startTag+e;return""});a=r.extendRegExp(e,"^","");this.selection=this.selection.replace(a,function(e){n.startTag=n.startTag+e;return""})}if(t){a=r.extendRegExp(t,"","$");this.selection=this.selection.replace(a,function(e){n.endTag=e+n.endTag;return""});a=r.extendRegExp(t,"^","");this.after=this.after.replace(a,function(e){n.endTag=e+n.endTag;return""})}};e.Chunks.prototype.trimWhitespace=function(e){this.selection=this.selection.replace(/^(\s*)/,"");if(!e){this.before+=n.$1}this.selection=this.selection.replace(/(\s*)$/,"");if(!e){this.after=n.$1+this.after}};e.Chunks.prototype.addBlankLines=function(e,t,a){if(e===undefined){e=1}if(t===undefined){t=1}e++;t++;var r;var i;if(navigator.userAgent.match(/Chrome/)){"X".match(/()./)}this.selection=this.selection.replace(/(^\n*)/,"");this.startTag=this.startTag+n.$1;this.selection=this.selection.replace(/(\n*$)/,"");this.endTag=this.endTag+n.$1;this.startTag=this.startTag.replace(/(^\n*)/,"");this.before=this.before+n.$1;this.endTag=this.endTag.replace(/(\n*$)/,"");this.after=this.after+n.$1;if(this.before){r=i="";while(e--){r+="\\n?";i+="\n"}if(a){r="\\n*"}this.before=this.before.replace(new n(r+"$",""),i)}if(this.after){r=i="";while(t--){r+="\\n?";i+="\n"}if(a){r="\\n*"}this.after=this.after.replace(new n(r,""),i)}};o.prefixes="(?:\\s{4,}|\\s*>|\\s*-\\s+|\\s*\\d+\\.|=|\\+|-|_|\\*|#|\\s*\\[[^\n]]+\\]:)";o.unwrap=function(e){var t=new n("([^\\n])\\n(?!(\\n|"+o.prefixes+"))","g");e.selection=e.selection.replace(t,"$1 $2")};o.wrap=function(e,t){o.unwrap(e);var a=new n("(.{1,"+t+"})( +|$\\n?)","gm");e.selection=e.selection.replace(a,function(e,t){if(new n("^"+o.prefixes,"").test(e)){return e}return t+"\n"});e.selection=e.selection.replace(/\s+$/,"")};o.doBold=function(e,t,n){return o.doBorI(e,2,"strong text")};o.doItalic=function(e,t,n){return o.doBorI(e,1,"emphasized text")};o.doBorI=function(e,t,a){e.trimWhitespace();e.selection=e.selection.replace(/\n{2,}/g,"\n");e.before.search(/(\**$)/);var r=n.$1;e.after.search(/(^\**)/);var i=n.$1;var o=Math.min(r.length,i.length);if(o>=t&&(o!=2||t!=1)){e.before=e.before.replace(n("[*]{"+t+"}$",""),"");e.after=e.after.replace(n("^[*]{"+t+"}",""),"")}else if(!e.selection&&i){e.after=e.after.replace(/^([*_]*)/,"");e.before=e.before.replace(/(\s?)$/,"");var l=n.$1;e.before=e.before+i+l}else{if(!e.selection&&!i){e.selection=a}var s=t<=1?"*":"**";e.before=e.before+s;e.after=s+e.after}return};o.stripLinkDefs=function(e,t){e=e.replace(/^[ ]{0,3}\[(\d+)\]:[ \t]*\n?[ \t]*<?(\S+?)>?[ \t]*\n?[ \t]*(?:(\n*)["(](.+?)[")][ \t]*)?(?:\n+|$)/gm,function(e,n,a,r,i){t[n]=e.replace(/\s*$/,"");if(r){t[n]=e.replace(/["(](.+?)[")]$/,"");return r+i}return""});return e};o.addLinkDef=function(e,t){var n=0;var a={};e.before=o.stripLinkDefs(e.before,a);e.selection=o.stripLinkDefs(e.selection,a);e.after=o.stripLinkDefs(e.after,a);var r="";var i=/(\[)((?:\[[^\]]*\]|[^\[\]])*)(\][ ]?(?:\n[ ]*)?\[)(\d+)(\])/g;var l=function(e){n++;e=e.replace(/^[ ]{0,3}\[(\d+)\]:/,"  ["+n+"]:");r+="\n"+e};var s=function(e,t,r,o,c,d){r=r.replace(i,s);if(a[c]){l(a[c]);return t+r+o+n+d}return e};e.before=e.before.replace(i,s);if(t){l(t)}else{e.selection=e.selection.replace(i,s)}var c=n;e.after=e.after.replace(i,s);if(e.after){e.after=e.after.replace(/\n*$/,"")}if(!e.after){e.selection=e.selection.replace(/\n*$/,"")}e.after+="\n\n"+r;return c};o.doLinkOrImage=function(e,t,n){e.trimWhitespace();e.findTags(/\s*!?\[/,/\][ ]?(?:\n[ ]*)?(\[.*?\])?/);if(e.endTag.length>1){e.startTag=e.startTag.replace(/!?\[/,"");e.endTag="";o.addLinkDef(e,null)}else{if(/\n\n/.test(e.selection)){o.addLinkDef(e,null);return}var a=function(a){if(a!==null){e.startTag=e.endTag="";var r=" [999]: "+a;var i=o.addLinkDef(e,r);e.startTag=n?"![":"[";e.endTag="]["+i+"]";if(!e.selection){if(n){e.selection="alt text"}else{e.selection="link text"}}}t()};if(n){r.prompt(s,u,a)}else{r.prompt(c,f,a)}return true}};r.makeAPI=function(){e.wmd={};e.wmd.editor=e.editor;e.wmd.previewManager=e.previewManager};r.startEditor=function(){if(e.wmd_env.autostart===false){r.makeAPI();return}var t;var n;var a=function(){e.panels=new e.PanelCollection;n=new e.previewManager;var a=n.refresh;t=new e.editor(a);n.refresh(true)};r.addEvent(top,"load",a)};e.previewManager=function(){var n=this;var a;var o;var s;var c;var d;var u;var f=3e3;var p="delayed";var v=function(t,n){r.addEvent(t,"input",n);t.onpaste=n;t.ondrop=n;r.addEvent(t,"keypress",n);r.addEvent(t,"keydown",n);o=new e.inputPoller(n,m)};var h=function(){var e=0;if(top.innerHeight){e=top.pageYOffset}else if(t.documentElement&&t.documentElement.scrollTop){e=t.documentElement.scrollTop}else if(t.body){e=t.body.scrollTop}return e};var g=function(t){if(!e.panels.preview&&!e.panels.output){return}var n=(new Date).getTime();if(!a&&e.showdown){a=new e.showdown.converter}if(a){t=a.makeHtml(t)}var r=(new Date).getTime();c=r-n;k(t);u=t};var y=function(){var t=e.panels.input.value;if(t&&t==d){return}else{d=t}b(t)};var b=function(e){var t=document.getElementById("previewer2");if(t==null){t=document.createElement("div");t.setAttribute("id","previewer2");t.style.display="none";document.body.appendChild(t)}t.innerHTML=e;MathJax.Hub.Queue(["Typeset",MathJax.Hub,"previewer2"],function(e){g(t.innerHTML)})};var w=function(){if(s){top.clearTimeout(s);s=undefined}if(p!=="manual"){var e=0;if(p==="delayed"){e=c}if(e>f){e=f}s=top.setTimeout(y,e)}};var x=function(e){if(e.scrollHeight<=e.clientHeight){return 1}return e.scrollTop/(e.scrollHeight-e.clientHeight)};var T=function(){if(e.panels.preview){e.panels.preview.scrollTop=(e.panels.preview.scrollHeight-e.panels.preview.clientHeight)*x(e.panels.preview)}if(e.panels.output){e.panels.output.scrollTop=(e.panels.output.scrollHeight-e.panels.output.clientHeight)*x(e.panels.output)}};this.refresh=function(e){if(e){d="";y()}else{w()}};this.processingTime=function(){return c};this.output=function(){return u};this.setUpdateMode=function(e){p=e;n.refresh()};var E=true;var k=function(t){var n=i.getTop(e.panels.input)-h();if(e.panels.output){if(e.panels.output.value!==undefined){e.panels.output.value=t;e.panels.output.readOnly=true}else{var a=t.replace(/&/g,"&amp;");a=a.replace(/</g,"&lt;");e.panels.output.innerHTML="<pre><code>"+a+"</code></pre>"}}if(e.panels.preview){e.panels.preview.innerHTML=t}T();if(E){E=false;return}var r=i.getTop(e.panels.input)-h();if(l.isIE){top.setTimeout(function(){top.scrollBy(0,r-n)},0)}else{top.scrollBy(0,r-n)}};var C=function(){v(e.panels.input,w);y();if(e.panels.preview){e.panels.preview.scrollTop=0}if(e.panels.output){e.panels.output.scrollTop=0}};this.destroy=function(){if(o){o.destroy()}};C()};o.doAutoindent=function(e,t,n){e.before=e.before.replace(/(\n|^)[ ]{0,3}([*+-]|\d+[.])[ \t]*\n$/,"\n\n");e.before=e.before.replace(/(\n|^)[ ]{0,3}>[ \t]*\n$/,"\n\n");e.before=e.before.replace(/(\n|^)[ \t]+\n$/,"\n\n");n=false;if(/(\n|^)[ ]{0,3}([*+-])[ \t]+.*\n$/.test(e.before)){if(o.doList){o.doList(e,t,false,true)}}if(/(\n|^)[ ]{0,3}(\d+[.])[ \t]+.*\n$/.test(e.before)){if(o.doList){o.doList(e,t,true,true)}}if(/(\n|^)[ ]{0,3}>[ \t]+.*\n$/.test(e.before)){if(o.doBlockquote){o.doBlockquote(e,t,n)}}if(/(\n|^)(\t|[ ]{4,}).*\n$/.test(e.before)){if(o.doCode){o.doCode(e,t,n)}}};o.doBlockquote=function(t,n,a){t.selection=t.selection.replace(/^(\n*)([^\r]+?)(\n*)$/,function(e,n,a,r){t.before+=n;t.after=r+t.after;return a});t.before=t.before.replace(/(>[ \t]*)$/,function(e,n){t.selection=n+t.selection;return""});var r=a?"Blockquote":"";t.selection=t.selection.replace(/^(\s|>)+$/,"");t.selection=t.selection||r;var i="";var l="";if(t.before){var s=t.before.replace(/\n$/,"").split("\n");var c=false;for(var d in s){var u=false;line=s[d];c=c&&line.length>0;if(/^>/.test(line)){u=true;if(!c&&line.length>1)c=true}else if(/^[ \t]*$/.test(line)){u=true}else{u=c}if(u){i+=line+"\n"}else{l+=i+line;i="\n"}}if(!/(^|\n)>/.test(i)){l+=i;i=""}}t.startTag=i;t.before=l;if(t.after){t.after=t.after.replace(/^\n?/,"\n")}t.after=t.after.replace(/^(((\n|^)(\n[ \t]*)*>(.+\n)*.*)+(\n[ \t]*)*)/,function(e){t.endTag=e;return""});var f=function(e){var n=e?"> ":"";if(t.startTag){t.startTag=t.startTag.replace(/\n((>|\s)*)\n$/,function(e,t){return"\n"+t.replace(/^[ ]{0,3}>?[ \t]*$/gm,n)+"\n"})}if(t.endTag){t.endTag=t.endTag.replace(/^\n((>|\s)*)\n/,function(e,t){return"\n"+t.replace(/^[ ]{0,3}>?[ \t]*$/gm,n)+"\n"})}};if(/^(?![ ]{0,3}>)/m.test(t.selection)){o.wrap(t,e.wmd_env.lineLength-2);t.selection=t.selection.replace(/^/gm,"> ");f(true);t.addBlankLines()}else{t.selection=t.selection.replace(/^[ ]{0,3}> ?/gm,"");o.unwrap(t);f(false);if(!/^(\n|^)[ ]{0,3}>/.test(t.selection)&&t.startTag){t.startTag=t.startTag.replace(/\n{0,2}$/,"\n\n")}if(!/(\n|^)[ ]{0,3}>.*$/.test(t.selection)&&t.endTag){t.endTag=t.endTag.replace(/^\n{0,2}/,"\n\n")}}if(!/\n/.test(t.selection)){t.selection=t.selection.replace(/^(> *)/,function(e,n){t.startTag+=n;return""})}};o.doCode=function(e,t,n){var a=/\S[ ]*$/.test(e.before);var r=/^[ ]*\S/.test(e.after);if(!r&&!a||/\n/.test(e.selection)){e.before=e.before.replace(/[ ]{4}$/,function(t){e.selection=t+e.selection;return""});var i=1;var o=1;if(/\n(\t|[ ]{4,}).*\n$/.test(e.before)||e.after===""){i=0}if(/^\n(\t|[ ]{4,})/.test(e.after)){o=0}e.addBlankLines(i,o);if(!e.selection){e.startTag="    ";e.selection=n?"enter code here":""}else{if(/^[ ]{0,3}\S/m.test(e.selection)){e.selection=e.selection.replace(/^/gm,"    ")}else{e.selection=e.selection.replace(/^[ ]{4}/gm,"")}}}else{e.trimWhitespace();e.findTags(/`/,/`/);if(!e.startTag&&!e.endTag){e.startTag=e.endTag="`";if(!e.selection){e.selection=n?"enter code here":""}}else if(e.endTag&&!e.startTag){e.before+=e.endTag;e.endTag=""}else{e.startTag=e.endTag=""}}};o.doList=function(t,a,r,i){var l=/(\n|^)(([ ]{0,3}([*+-]|\d+[.])[ \t]+.*)(\n.+|\n{2,}([*+-].*|\d+[.])[ \t]+.*|\n{2,}[ \t]+\S.*)*)\n*$/;var s=/^\n*(([ ]{0,3}([*+-]|\d+[.])[ \t]+.*)(\n.+|\n{2,}([*+-].*|\d+[.])[ \t]+.*|\n{2,}[ \t]+\S.*)*)\n*/;var c="-";var d=1;var u=function(){var e;if(r){e=" "+d+". ";d++}else{e=" "+c+" "}return e};var f=function(e){if(r===undefined){r=/^\s*\d/.test(e)}e=e.replace(/^[ ]{0,3}([*+-]|\d+[.])\s/gm,function(e){return u()});return e};t.findTags(/(\n|^)*[ ]{0,3}([*+-]|\d+[.])\s+/,null);if(t.before&&!/\n$/.test(t.before)&&!/^\n/.test(t.startTag)){t.before+=t.startTag;t.startTag=""}if(t.startTag){var p=/\d+[.]/.test(t.startTag);t.startTag="";t.selection=t.selection.replace(/\n[ ]{4}/g,"\n");o.unwrap(t);t.addBlankLines();if(p){t.after=t.after.replace(s,f)}if(r==p){return}}var m=1;t.before=t.before.replace(l,function(e){if(/^\s*([*+-])/.test(e)){c=n.$1}m=/[^\n]\n\n[^\n]/.test(e)?1:0;return f(e)});if(!t.selection){t.selection=i?"List item":" "}var v=u();var h=1;t.after=t.after.replace(s,function(e){h=/[^\n]\n\n[^\n]/.test(e)?1:0;return f(e)});t.trimWhitespace(true);t.addBlankLines(m,h,true);t.startTag=v;var g=v.replace(/./g," ");o.wrap(t,e.wmd_env.lineLength-g.length);t.selection=t.selection.replace(/\n/g,"\n"+g)};o.doHeading=function(t,a,r){t.selection=t.selection.replace(/\s+/g," ");t.selection=t.selection.replace(/(^\s+|\s+$)/g,"");if(!t.selection){t.startTag="## ";t.selection="Heading";t.endTag=" ##";return}var i=0;t.findTags(/#+[ ]*/,/[ ]*#+/);if(/#+/.test(t.startTag)){i=n.lastMatch.length}t.startTag=t.endTag="";t.findTags(null,/\s?(-+|=+)/);if(/=+/.test(t.endTag)){i=1}if(/-+/.test(t.endTag)){i=2}t.startTag=t.endTag="";t.addBlankLines(1,1);var o=i==0?2:i-1;if(o>0){var l=o>=2?"-":"=";var s=t.selection.length;if(s>e.wmd_env.lineLength){s=e.wmd_env.lineLength}t.endTag="\n";while(s--){t.endTag+=l}}};o.doHorizontalRule=function(e,t,n){e.startTag="----------\n";e.selection="";e.addBlankLines(2,1,true)}};Attacklab.wmd_env={};Attacklab.account_options={};Attacklab.wmd_defaults={version:1,output:"HTML",
lineLength:40,delayLoad:false};if(!Attacklab.wmd){Attacklab.wmd=function(){Attacklab.loadEnv=function(){var e=function(e){if(!e){return}for(var t in e){Attacklab.wmd_env[t]=e[t]}};e(Attacklab.wmd_defaults);e(Attacklab.account_options);e(top["wmd_options"]);Attacklab.full=true;var t="bold italic link blockquote code image ol ul heading hr";Attacklab.wmd_env.buttons=Attacklab.wmd_env.buttons||t};Attacklab.loadEnv()};Attacklab.wmd();Attacklab.wmdBase();Attacklab.Util.startEditor()}