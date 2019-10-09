<script>
if (typeof(twttr) !== 'undefined') {
    twttr.widgets.load();
}
window.twttr = (function(d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0],
        t = window.twttr || {};
    if (d.getElementById(id)) return t;
    js = d.createElement(s);
    js.id = id;
    js.src = "https://platform.twitter.com/widgets.js";
    fjs.parentNode.insertBefore(js, fjs);

    t._e = [];
    t.ready = function(f) {
        t._e.push(f);
    };

    return t;
}(document, "script", "twitter-wjs"));
</script>
<?php
foreach($tweets as $id => $name) {
  echo '<blockquote class="twitter-tweet" data-cards="hidden" data-lang="en"><a href="' . "https://twitter.com/" . $name . "/status/" . $id . '" title="' . $name . '"> </a></blockquote>';
}