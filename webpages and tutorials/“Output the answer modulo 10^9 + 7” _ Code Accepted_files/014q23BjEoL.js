define("DetailsPriorityFitter",[nut,"StyleUtils","EventUtils"],function(h,t,v){var w="itemMediaContainer title buyingPrice shippingDisclaimer ppuPrice listPrice byLine prime author callToAction-wrapper customerReviews format brand".split(" "),x="itemMediaContainer title buyingPrice shippingDisclaimer ppuPrice listPrice byLine prime author customerReviews callToAction-wrapper format brand".split(" "),u,q=function(c){for(var k=0;k<c.length;k++)for(var l=c[k],n=l.getBoundingClientRect(),a=r(l),d=0;d<
a.length;d++){var b=h("."+a[d],l)[0];if(b&&(b=b.getBoundingClientRect(),b.bottom>u||b.bottom>n.bottom))return!1}return!0},r=function(c){return t.existsClass("noPrice",c.className)?x:w},p=function(c,k){u=h("#container")[0].getBoundingClientRect().bottom;k(h(".truncate"));for(var l={},n={},a=0;a<c.length;++a){var d=c[a];l[a]={};n[a]=[];for(var b=r(d),f=0;f<b.length;++f){var g=b[f],e=h("."+g,d)[0];e&&(l[a][g]=t.getStyle(e,"display"),e.style.display="none")}}d=0;g=Array(c.length);for(f=0;f<g.length;f++)g[f]=
!0;do{f=!1;for(a=0;a<c.length;++a)if(e=c[a],b=r(e),g[a]&&!(d>=b.length)){var f=!0,b=b[d],m=h("."+b,e)[0];if(m)if(m.style.display=l[a][b],"none"==m.style.display)e.className+=" "+b+"Hidden",0==d&&(g[a]=!1);else{if(!q(c)&&(k(h(".truncate",m)),!q(c))){for(var p=n[a],s=p.length-1;0<=s&&(k(h(".truncate",p[s])),!q(c));--s);if(!q(c)){m.style.display="none";e.className+=" "+b+"Hidden";0==d&&(g[a]=!1);continue}}e.className+=" "+b+"Shown";n[a].push(m)}}d++}while(f);v.trigger("dra-details-prioritized",!0)};
p.autoTruncates=!0;return p});