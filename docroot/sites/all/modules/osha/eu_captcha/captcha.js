captchaUtils = {
    JSONP: (function() {
        var a = 0,
            c, f, b, d = this;

        function e(j) {
            var i = document.createElement("SCRIPT"),
                h = false;
            i.src = j;
            i.async = true;
            i.onload = i.onreadystatechange = function() {
                if (!h && (!this.readyState || this.readyState === "loaded" || this.readyState === "complete")) {
                    h = true;
                    i.onload = i.onreadystatechange = null;
                    if (i && i.parentNode) {
                        i.parentNode.removeChild(i)
                    }
                }
            };
            if (!c) {
                c = document.getElementsByTagName("head")[0]
            }
            c.appendChild(i)
        }

        function g(h, j, k) {
            f = "?";
            j = j || {};
            for (b in j) {
                if (j.hasOwnProperty(b)) {
                    f += encodeURIComponent(b) + "=" + encodeURIComponent(j[b]) + "&"
                }
            }
            var i = "json" + (++a);
            d[i] = function(l) {
                k(l);
                try {
                    delete d[i]
                } catch (m) {}
                d[i] = null
            };
            e(h + f + "callback=" + Math.random());
            return i
        }
        return {
            get: g
        }
    }()),
    parseJson: function(json) {
        if (/^[\],:{}\s]*$/.test(json.replace(/\\(?:["'\\\/bfnrt]|u[0-9a-fA-F]{4})/g, "@").replace(/["'][^"'\\\n\r]*["']|true|false|null|-?\d+(?:\.\d*)?(?:[eE][+\-]?\d+)?/g, "]").replace(/(?:^|:|,)(?:\s*\[)+/g, ""))) {
            return eval("(" + json + ")")
        } else {
            return ""
        }
    },
    MD5: function(s) {
        function L(b, a) {
            return (b << a) | (b >>> (32 - a))
        }

        function K(k, b) {
            var F, a, d, x, c;
            d = (k & 2147483648);
            x = (b & 2147483648);
            F = (k & 1073741824);
            a = (b & 1073741824);
            c = (k & 1073741823) + (b & 1073741823);
            if (F & a) {
                return (c ^ 2147483648 ^ d ^ x)
            }
            if (F | a) {
                if (c & 1073741824) {
                    return (c ^ 3221225472 ^ d ^ x)
                } else {
                    return (c ^ 1073741824 ^ d ^ x)
                }
            } else {
                return (c ^ d ^ x)
            }
        }

        function r(a, c, b) {
            return (a & c) | ((~a) & b)
        }

        function q(a, c, b) {
            return (a & b) | (c & (~b))
        }

        function p(a, c, b) {
            return (a ^ c ^ b)
        }

        function n(a, c, b) {
            return (c ^ (a | (~b)))
        }

        function u(G, F, aa, Z, k, H, I) {
            G = K(G, K(K(r(F, aa, Z), k), I));
            return K(L(G, H), F)
        }

        function f(G, F, aa, Z, k, H, I) {
            G = K(G, K(K(q(F, aa, Z), k), I));
            return K(L(G, H), F)
        }

        function D(G, F, aa, Z, k, H, I) {
            G = K(G, K(K(p(F, aa, Z), k), I));
            return K(L(G, H), F)
        }

        function t(G, F, aa, Z, k, H, I) {
            G = K(G, K(K(n(F, aa, Z), k), I));
            return K(L(G, H), F)
        }

        function e(k) {
            var G;
            var d = k.length;
            var c = d + 8;
            var b = (c - (c % 64)) / 64;
            var F = (b + 1) * 16;
            var H = Array(F - 1);
            var a = 0;
            var x = 0;
            while (x < d) {
                G = (x - (x % 4)) / 4;
                a = (x % 4) * 8;
                H[G] = (H[G] | (k.charCodeAt(x) << a));
                x++
            }
            G = (x - (x % 4)) / 4;
            a = (x % 4) * 8;
            H[G] = H[G] | (128 << a);
            H[F - 2] = d << 3;
            H[F - 1] = d >>> 29;
            return H
        }

        function B(c) {
            var b = "",
                d = "",
                k, a;
            for (a = 0; a <= 3; a++) {
                k = (c >>> (a * 8)) & 255;
                d = "0" + k.toString(16);
                b = b + d.substr(d.length - 2, 2)
            }
            return b
        }

        function J(b) {
            b = b.replace(/\r\n/g, "\n");
            var a = "";
            for (var k = 0; k < b.length; k++) {
                var d = b.charCodeAt(k);
                if (d < 128) {
                    a += String.fromCharCode(d)
                } else {
                    if ((d > 127) && (d < 2048)) {
                        a += String.fromCharCode((d >> 6) | 192);
                        a += String.fromCharCode((d & 63) | 128)
                    } else {
                        a += String.fromCharCode((d >> 12) | 224);
                        a += String.fromCharCode(((d >> 6) & 63) | 128);
                        a += String.fromCharCode((d & 63) | 128)
                    }
                }
            }
            return a
        }
        var C = Array();
        var P, h, E, v, g, Y, X, W, V;
        var S = 7,
            Q = 12,
            N = 17,
            M = 22;
        var A = 5,
            z = 9,
            y = 14,
            w = 20;
        var o = 4,
            m = 11,
            l = 16,
            j = 23;
        var U = 6,
            T = 10,
            R = 15,
            O = 21;
        s = J(s);
        C = e(s);
        Y = 1732584193;
        X = 4023233417;
        W = 2562383102;
        V = 271733878;
        for (P = 0; P < C.length; P += 16) {
            h = Y;
            E = X;
            v = W;
            g = V;
            Y = u(Y, X, W, V, C[P + 0], S, 3614090360);
            V = u(V, Y, X, W, C[P + 1], Q, 3905402710);
            W = u(W, V, Y, X, C[P + 2], N, 606105819);
            X = u(X, W, V, Y, C[P + 3], M, 3250441966);
            Y = u(Y, X, W, V, C[P + 4], S, 4118548399);
            V = u(V, Y, X, W, C[P + 5], Q, 1200080426);
            W = u(W, V, Y, X, C[P + 6], N, 2821735955);
            X = u(X, W, V, Y, C[P + 7], M, 4249261313);
            Y = u(Y, X, W, V, C[P + 8], S, 1770035416);
            V = u(V, Y, X, W, C[P + 9], Q, 2336552879);
            W = u(W, V, Y, X, C[P + 10], N, 4294925233);
            X = u(X, W, V, Y, C[P + 11], M, 2304563134);
            Y = u(Y, X, W, V, C[P + 12], S, 1804603682);
            V = u(V, Y, X, W, C[P + 13], Q, 4254626195);
            W = u(W, V, Y, X, C[P + 14], N, 2792965006);
            X = u(X, W, V, Y, C[P + 15], M, 1236535329);
            Y = f(Y, X, W, V, C[P + 1], A, 4129170786);
            V = f(V, Y, X, W, C[P + 6], z, 3225465664);
            W = f(W, V, Y, X, C[P + 11], y, 643717713);
            X = f(X, W, V, Y, C[P + 0], w, 3921069994);
            Y = f(Y, X, W, V, C[P + 5], A, 3593408605);
            V = f(V, Y, X, W, C[P + 10], z, 38016083);
            W = f(W, V, Y, X, C[P + 15], y, 3634488961);
            X = f(X, W, V, Y, C[P + 4], w, 3889429448);
            Y = f(Y, X, W, V, C[P + 9], A, 568446438);
            V = f(V, Y, X, W, C[P + 14], z, 3275163606);
            W = f(W, V, Y, X, C[P + 3], y, 4107603335);
            X = f(X, W, V, Y, C[P + 8], w, 1163531501);
            Y = f(Y, X, W, V, C[P + 13], A, 2850285829);
            V = f(V, Y, X, W, C[P + 2], z, 4243563512);
            W = f(W, V, Y, X, C[P + 7], y, 1735328473);
            X = f(X, W, V, Y, C[P + 12], w, 2368359562);
            Y = D(Y, X, W, V, C[P + 5], o, 4294588738);
            V = D(V, Y, X, W, C[P + 8], m, 2272392833);
            W = D(W, V, Y, X, C[P + 11], l, 1839030562);
            X = D(X, W, V, Y, C[P + 14], j, 4259657740);
            Y = D(Y, X, W, V, C[P + 1], o, 2763975236);
            V = D(V, Y, X, W, C[P + 4], m, 1272893353);
            W = D(W, V, Y, X, C[P + 7], l, 4139469664);
            X = D(X, W, V, Y, C[P + 10], j, 3200236656);
            Y = D(Y, X, W, V, C[P + 13], o, 681279174);
            V = D(V, Y, X, W, C[P + 0], m, 3936430074);
            W = D(W, V, Y, X, C[P + 3], l, 3572445317);
            X = D(X, W, V, Y, C[P + 6], j, 76029189);
            Y = D(Y, X, W, V, C[P + 9], o, 3654602809);
            V = D(V, Y, X, W, C[P + 12], m, 3873151461);
            W = D(W, V, Y, X, C[P + 15], l, 530742520);
            X = D(X, W, V, Y, C[P + 2], j, 3299628645);
            Y = t(Y, X, W, V, C[P + 0], U, 4096336452);
            V = t(V, Y, X, W, C[P + 7], T, 1126891415);
            W = t(W, V, Y, X, C[P + 14], R, 2878612391);
            X = t(X, W, V, Y, C[P + 5], O, 4237533241);
            Y = t(Y, X, W, V, C[P + 12], U, 1700485571);
            V = t(V, Y, X, W, C[P + 3], T, 2399980690);
            W = t(W, V, Y, X, C[P + 10], R, 4293915773);
            X = t(X, W, V, Y, C[P + 1], O, 2240044497);
            Y = t(Y, X, W, V, C[P + 8], U, 1873313359);
            V = t(V, Y, X, W, C[P + 15], T, 4264355552);
            W = t(W, V, Y, X, C[P + 6], R, 2734768916);
            X = t(X, W, V, Y, C[P + 13], O, 1309151649);
            Y = t(Y, X, W, V, C[P + 4], U, 4149444226);
            V = t(V, Y, X, W, C[P + 11], T, 3174756917);
            W = t(W, V, Y, X, C[P + 2], R, 718787259);
            X = t(X, W, V, Y, C[P + 9], O, 3951481745);
            Y = K(Y, h);
            X = K(X, E);
            W = K(W, v);
            V = K(V, g)
        }
        var i = B(Y) + B(X) + B(W) + B(V);
        return i.toLowerCase()
    },
    getElementsByClassName: function(b, a, c) {
        if (document.getElementsByClassName) {
            getElementsByClassName = function(j, m, h) {
                h = h || document;
                var d = h.getElementsByClassName(j),
                    l = (m) ? new RegExp("\\b" + m + "\\b", "i") : null,
                    e = [],
                    g;
                for (var f = 0, k = d.length; f < k; f += 1) {
                    g = d[f];
                    if (!l || l.test(g.nodeName)) {
                        e.push(g)
                    }
                }
                return e
            }
        } else {
            if (document.evaluate) {
                getElementsByClassName = function(o, r, n) {
                    r = r || "*";
                    n = n || document;
                    var g = o.split(" "),
                        p = "",
                        l = "http://www.w3.org/1999/xhtml",
                        q = (document.documentElement.namespaceURI === l) ? l : null,
                        h = [],
                        d, f;
                    for (var i = 0, k = g.length; i < k; i += 1) {
                        p += "[contains(concat(' ', @class, ' '), ' " + g[i] + " ')]"
                    }
                    try {
                        d = document.evaluate(".//" + r + p, n, q, 0, null)
                    } catch (m) {
                        d = document.evaluate(".//" + r + p, n, null, 0, null)
                    }
                    while ((f = d.iterateNext())) {
                        h.push(f)
                    }
                    return h
                }
            } else {
                getElementsByClassName = function(r, u, q) {
                    u = u || "*";
                    q = q || document;
                    var h = r.split(" "),
                        t = [],
                        d = (u === "*" && q.all) ? q.all : q.getElementsByTagName(u),
                        p, j = [],
                        o;
                    for (var i = 0, e = h.length; i < e; i += 1) {
                        t.push(new RegExp("(^|\\s)" + h[i] + "(\\s|$)"))
                    }
                    for (var g = 0, s = d.length; g < s; g += 1) {
                        p = d[g];
                        o = false;
                        for (var f = 0, n = t.length; f < n; f += 1) {
                            o = t[f].test(p.className);
                            if (!o) {
                                break
                            }
                        }
                        if (o) {
                            j.push(p)
                        }
                    }
                    return j
                }
            }
        }
        return getElementsByClassName(b, a, c)
    },
    addEvent: function(d, c, a) {
        if (d.addEventListener) {
            d.addEventListener(c, a, false);
            return true
        } else {
            if (d.attachEvent) {
                var b = d.attachEvent("on" + c, a);
                return b
            } else {
                return false
            }
        }
    },
    loadJsCssFile: function(a, b) {
        var c;
        if (b == "js") {
            c = document.createElement("SCRIPT");
            c.setAttribute("type", "text/javascript");
            c.setAttribute("src", a)
        } else {
            if (b == "css") {
                c = document.createElement("LINK");
                c.setAttribute("rel", "stylesheet");
                c.setAttribute("type", "text/css");
                c.setAttribute("href", a)
            }
        } if (typeof c !== "undefined") {
            document.getElementsByTagName("head")[0].appendChild(c)
        }
    },
    clone: function(c) {
        if (c == null || typeof(c) != "object") {
            return c
        }
        var a = new c.constructor();
        for (var b in c) {
            a[b] = this.clone(c[b])
        }
        return a
    },
    createIeObject: function(a, b, d) {
        var c = document.createElement("DIV");
        c.innerHTML = '<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" class="' + b + '" id="' + d + '" height="0" width="0"><param name="movie" value="' + a + '"></object>';
        return c.firstChild
    },
    keyCheck: function(b) {
        var a = (window.event) ? event.keyCode : b.keyCode;
        return a
    },
    enableIndexOf: function() {
        if (!Array.prototype.indexOf) {
            Array.prototype.indexOf = function(c) {
                if (this == null) {
                    throw new TypeError()
                }
                var e, b, d = Object(this),
                    a = d.length >>> 0;
                if (a === 0) {
                    return -1
                }
                e = 0;
                if (arguments.length > 1) {
                    e = Number(arguments[1]);
                    if (e != e) {
                        e = 0
                    } else {
                        if (e != 0 && e != Infinity && e != -Infinity) {
                            e = (e > 0 || -1) * Math.floor(Math.abs(e))
                        }
                    }
                }
                if (e >= a) {
                    return -1
                }
                for (b = e >= 0 ? e : Math.max(a - Math.abs(e), 0); b < a; b++) {
                    if (b in d && d[b] === c) {
                        return b
                    }
                }
                return -1
            }
        }
    },
    getLanguage: function() {
        var a = "";
        a = this.getLangFromURL();
        if (a === "" || a === undefined) {
            a = this.getLangFromHtml()
        }
        if (a === "" || a === undefined) {
            a = this.getLangFromMeta("http-equiv")
        }
        if (a === "" || a === undefined) {
            a = this.getLangFromMeta("meta-language")
        }
        if (a === "" || a === undefined) {
            a = this.getLangFromMeta("")
        }
        if (a === undefined) {
            return undefined
        }
        return a.toLowerCase()
    },
    getLangFromURL: function() {
        var d = "(_|-)([a-zA-Z]{2}).(html?|php|asp|cgi|jsp|cfm|xml|rss)";
        var c = new RegExp(d, "gi");
        var a = document.location.href;
        var b;
        a = c.exec(a);
        if (a !== null) {
            if (a[2] !== null) {
                b = a[2]
            }
        } else {
            return undefined
        }
        return b.toLowerCase()
    },
    getLangFromHtml: function() {
        return document.getElementsByTagName("html")[0].lang.toLowerCase()
    },
    getLangFromMeta: function(b) {
        var c = document.getElementsByTagName("META");
        var a;
        for (a = 0; a < c.length; a++) {
            if (b === "http-equiv") {
                if (c[a].httpEquiv.toLowerCase() === "content-language") {
                    if (c[a].content) {
                        return c[a].content.substring(0, 2).toLowerCase()
                    }
                }
            } else {
                if (b === "meta-language") {
                    if (c[a].name.toLowerCase() === "language") {
                        if (c[a].content) {
                            return c[a].content.substring(0, 2).toLowerCase()
                        }
                    }
                } else {
                    if (c[a].name.toLowerCase() === "language") {
                        if (c[a].content) {
                            return c[a].content.substring(0, 2).toLowerCase()
                        }
                    }
                }
            }
        }
        return undefined
    }
};
captcha = {
    sid: "",
    session_name: "",
    prefix: "captcha_",
    captchas: null,
    captchaObjects: new Array(),
    server: "//webtools.ec.europa.eu",
    path: "/captcha",
    path_sid: "/securimage_sessionid.php",
    path_code: "/securimage_crypted.php",
    path_img: "/CaptchaSecurityImages.php",
    path_audio: "/securimage_play.php",
    path_swf: "/securimage_play_autoplay.swf",
    path_css: "/css/captcha.css",
    path_icon_play: "/images/audio.png",
    path_icon_loading: "/images/load.gif",
    path_icon_refresh: "/images/refresh.png",
    params_img: "&width=100&height=40&characters=5",
    eu_langs: ["bg", "cs", "da", "de", "el", "en", "es", "et", "fr", "ga", "hr", "it", "lt", "lv", "hu", "mt", "nl", "pl", "pt", "ro", "sk", "sl", "fi", "sv"],
    labels: {
        bg: {
            img: "Код за сигурност",
            refresh: "Нов код",
            read: "Прослушване на кода",
            type: {
                string: "Въведете кода за сигурност",
                math: "Въведете решението на задачата"
            }
        },
        cs: {
            img: "Text pro ověření identity",
            refresh: "Zkusit jiný text",
            read: "Nechat text přečíst počítačem",
            type: {
                string: "Zobrazený text vepište sem",
                math: "Výsledek napište sem"
            }
        },
        da: {
            img: "Captcha-billede",
            refresh: "Opdatér captcha",
            read: "Lyt til lydudgaven",
            type: {
                string: "Indtast captcha-koden",
                math: "Indtast løsningen på regnestykket"
            }
        },
        de: {
            img: "Captcha-Bild",
            refresh: "Neue Zeichenfolge anfordern",
            read: "Zeichenfolge vorlesen",
            type: {
                string: "Zeichenfolge eingeben",
                math: "Rechenergebnis eingeben"
            }
        },
        el: {
            img: 'Κωδικός "captcha"',
            refresh: 'Ανανέωση κωδικού "captcha"',
            read: 'Ανάγνωση ηχητικού κωδικού "captcha"',
            type: {
                string: "Πληκτρολογήστε τους χαρακτήρες που βλέπετε",
                math: "Δώστε τη λύση σ' αυτό το πρόβλημα"
            }
        },
        en: {
            img: "Captcha picture",
            refresh: "Refresh captcha",
            read: "Read audio captcha",
            type: {
                string: "Type visual confirmation",
                math: "Provide the solution to this math problem"
            }
        },
        es: {
            img: "Imagen CAPTCHA",
            refresh: "Actualizar CAPTCHA",
            read: "Reproducir CAPTCHA de audio",
            type: {
                string: "Teclear confirmación visual",
                math: "Resolver problema matemático"
            }
        },
        et: {
            img: "Kontrollpilt",
            refresh: "Uuenda kontrollkoodi",
            read: "Käivita audio kontrolltekst",
            type: {
                string: "Trükkige visuaalne kinnitus",
                math: "Esitage matemaatilise tehte vastus"
            }
        },
        fi: {
            img: "Varmennekuva",
            refresh: "Vaihda varmenne",
            read: "Lue äänivarmenne",
            type: {
                string: "Kirjoita näkyvä varmennekoodi",
                math: "Kirjoita laskutoimituksen tulos"
            }
        },
        fr: {
            img: "Image de vérification (captcha)",
            refresh: "Afficher une autre image de vérification (captcha)",
            read: "Écouter le code de vérification (captcha audio)",
            type: {
                string: "Taper la confirmation visuelle",
                math: "Donner la solution de ce problème mathématique"
            }
        },
        ga: {
            img: "Pictiúr captcha",
            refresh: "An captcha a athnuachan",
            read: "An captcha a chloisteáil",
            type: {
                string: "Iontráil an deimhniú  amhairc",
                math: "Réitigh an cheist seo"
            }
        },
        hr: {
            img: "CAPTCHA kôd",
            refresh: "Osvježi CAPTCHA kôd",
            read: "Pročitaj CAPTCHA kôd",
            type: {
                string: "Unesite CAPTCHA kôd",
                math: "Unesite rezultat jednadžbe"
            }
        },
        hu: {
            img: "Karakterfelismerés („captcha”)",
            refresh: "A képen megjelenített karakterek frissítése",
            read: "A karakterek felolvasása",
            type: {
                string: "Gépelje be a képen megjelenített karaktereket",
                math: "Gépelje be a matematikai művelet végeredményét"
            }
        },
        it: {
            img: "Immagine captcha",
            refresh: "Visualizzare un'altra immagine captcha",
            read: "Ascoltare la lettura del codice captcha",
            type: {
                string: "Digitare i caratteri dell'immagine captcha",
                math: "Digitare il risultato dell'operazione matematica"
            }
        },
        lt: {
            img: "Ženklų testas",
            refresh: "Atnaujinti ženklų testą",
            read: "Diktuoti ženklų testą",
            type: {
                string: "Įrašykite ženklus",
                math: "Įrašykite šios matematikos užduoties atsakymą"
            }
        },
        lv: {
            img: "Autentifikācijas koda attēls",
            refresh: "Pieprasīt jaunu autentifikācijas kodu",
            read: "Nolasīt autentifikācijas kodu",
            type: {
                string: "Ierakstiet attēlā redzamās rakstzīmes",
                math: "Ierakstiet uzdevuma atrisinājumu"
            }
        },
        mt: {
            img: "Stampa Captcha",
            refresh: "Iffriska mill-ġdid il-captcha",
            read: "Aqra l-captcha awdjo",
            type: {
                string: "Ittajpja l-konferma viżwali",
                math: "Agħti s-soluzzjoni ta' din il-problema tal-matematika"
            }
        },
        nl: {
            img: "Visuele captcha",
            refresh: "Andere captcha bekijken",
            read: "Audiocaptcha beluisteren",
            type: {
                string: "Welke tekens staan er op de afbeelding?",
                math: "Wat is de uitkomst van deze rekensom?"
            }
        },
        pl: {
            img: "Kod CAPTCHA",
            refresh: "Odśwież kod CAPTCHA",
            read: "Odtwórz nagranie kodu CAPTCHA",
            type: {
                string: "Wpisz kod CAPTCHA",
                math: "Rozwiąż zadanie"
            }
        },
        pt: {
            img: "Imagem CAPTCHA",
            refresh: "Atualizar CAPTCHA",
            read: "Transcreva o CAPTCHA áudio",
            type: {
                string: "Transcreva os carateres que vê na imagem",
                math: "Escreva o resultado da operação matemática"
            }
        },
        ro: {
            img: "Cod de securitate vizual",
            refresh: "Reîmprospătează codul de securitate vizual",
            read: "Citeşte codul de securitate audio",
            type: {
                string: "Introduceţi codul de securitate",
                math: "Introduceţi rezultatul operaţiei matematice"
            }
        },
        sk: {
            img: "Kontrolný text",
            refresh: "Skúsiť iný kontrolný text",
            read: "Prehrať kontrolný text",
            type: {
                string: "Napíšte zobrazený text",
                math: "Napíšte riešenie"
            }
        },
        sl: {
            img: "Slika varnostne kode",
            refresh: "Osveži varnostno kodo",
            read: "Preberi varnostno kodo",
            type: {
                string: "Vpišite znake s slike",
                math: "Rešite matematično vprašanje"
            }
        },
        sv: {
            img: "Säkerhetskod",
            refresh: "Visa ny kod",
            read: "Lyssna på ljudversionen",
            type: {
                string: "Skriv det du ser på bilden",
                math: "Skriv lösningen på talet"
            }
        }
    },
    lang: "en",
    conf_type: "string",
    conf_perturbation: 0.6,
    conf_num_lines: Math.floor(Math.random() * 4) + 6,
    conf_noise_level: 0,
    conf_length: 6,
    conf_case_sensitive: false,
    conf_image_bg_color: "",
    conf_text_color: "",
    conf_line_color: "",
    conf_noise_color: "",
    conf_text_transparency_percentage: "",
    conf_use_transparent_text: false,
    conf_background_directory: "",
    autodetect_protocol: true,
    autoinsert_confirmation_field: true,
    id_confirmation_field: "security_code",
    label_confirmation_field: null,
    loadConfig: function(e, g) {
        var c = document.getElementById(g),
            b, a, f, d;
        if (c !== null && typeof c !== "undefined") {
            b = c.innerHTML.replace(/ *<!-* */g, "");
            b = b.replace(/ *\/*-*> */g, "");
            b = b.replace(/#/g, "%23");
            d = /\{[^\{\}]*\}/;
            if (d.exec(b)) {
                a = captchaUtils.parseJson(b)
            }
            if (typeof a !== "undefined") {
                if (typeof a.server === "string") {
                    f = a.server;
                    if (f) {
                        e.server = f
                    }
                }
                if (typeof a.path === "string") {
                    f = a.path;
                    if (f) {
                        e.path = f
                    }
                }
                defaultLanguage = this.lang;
                if (typeof a.lang == "undefined") {
                    e.lang = (captchaUtils.getLanguage() === undefined) ? defaultLanguage : captchaUtils.getLanguage()
                } else {
                    if (a.lang === "http-equiv" || a.lang === "meta-language") {
                        if (captchaUtils.getLangFromMeta(a.lang)) {
                            e.lang = captchaUtils.getLangFromMeta(a.lang)
                        }
                    } else {
                        if (a.lang === "html-lang") {
                            if (captchaUtils.getLangFromHtml()) {
                                e.lang = captchaUtils.getLangFromHtml()
                            }
                        } else {
                            if (a.lang === "url") {
                                if (captchaUtils.getLangFromURL()) {
                                    e.lang = captchaUtils.getLangFromURL()
                                }
                            } else {
                                e.lang = a.lang
                            }
                        }
                    }
                } if (this.eu_langs.indexOf(e.lang) < 0) {
                    e.lang = defaultLanguage
                }
                if (typeof a.type !== "undefined") {
                    f = a.type;
                    if (f == "string" || f == "math") {
                        e.conf_type = f
                    }
                }
                if (typeof a.perturbation === "number") {
                    f = a.perturbation;
                    if (f) {
                        e.conf_perturbation = f
                    }
                }
                if (typeof a.num_lines === "number") {
                    f = a.num_lines;
                    if (f) {
                        e.conf_num_lines = f
                    }
                }
                if (typeof a.noise_level === "number") {
                    f = a.noise_level;
                    if (f) {
                        e.conf_noise_level = f
                    }
                }
                if (typeof a.length === "number") {
                    f = a.length;
                    if (f) {
                        e.conf_length = f
                    }
                }
                if (typeof a.case_sensitive === "boolean") {
                    f = a.case_sensitive;
                    e.conf_case_sensitive = f
                }
                if (typeof a.image_bg_color === "string") {
                    f = a.image_bg_color;
                    if (f) {
                        e.conf_image_bg_color = f
                    }
                }
                if (typeof a.text_color === "string") {
                    f = a.text_color;
                    if (f) {
                        e.conf_text_color = f
                    }
                }
                if (typeof a.line_color === "string") {
                    f = a.line_color;
                    if (f) {
                        e.conf_line_color = f
                    }
                }
                if (typeof a.noise_color === "string") {
                    f = a.noise_color;
                    if (f) {
                        e.conf_noise_color = f
                    }
                }
                if (typeof a.background_directory === "string") {
                    f = a.background_directory;
                    if (f) {
                        e.conf_background_directory = f
                    }
                }
                if (typeof a.text_transparency_percentage === "number") {
                    f = a.text_transparency_percentage;
                    if (f) {
                        e.conf_text_transparency_percentage = f
                    }
                }
                if (typeof a.use_transparent_text === "boolean") {
                    f = a.use_transparent_text;
                    e.conf_use_transparent_text = f
                }
                if (typeof a.autodetect_protocol === "boolean") {
                    f = a.autodetect_protocol;
                    e.autodetect_protocol = f
                }
                if (typeof a.autoinsert_confirmation_field === "boolean") {
                    f = a.autoinsert_confirmation_field;
                    e.autoinsert_confirmation_field = f
                }
                if (typeof a.id_confirmation_field === "string") {
                    f = a.id_confirmation_field;
                    if (f) {
                        e.id_confirmation_field = f
                    }
                }
                if (typeof a.label_confirmation_field === "string") {
                    f = a.label_confirmation_field;
                    if (f !== null) {
                        e.label_confirmation_field = f
                    }
                }
            }
        }
    },
    init: function() {
        this.captchas = captchaUtils.getElementsByClassName("captcha", "span");
        if (typeof this.captchas !== "undefined" && typeof this.captchas === "object" && this.captchas.length) {
            captchaUtils.enableIndexOf();
            this.loadConfig(this, "captchaconfig");
            if (this.autodetect_protocol) {
                this.server = this.server.replace(/https?:/gi, document.location.protocol)
            }
            var a = this.server + this.path + this.path_sid;
            captchaUtils.loadJsCssFile(this.server + this.path + this.path_css, "css");
            captchaUtils.JSONP.get(a, {}, function(b) {})
        }
    },
    initCaptchas: function(b) {
        this.sid = b.sid;
        this.session_name = b.session_name;
        var a = 0;
        for (a = 0; a < this.captchas.length; a++) {
            this.captchas[a].id = captcha.prefix + a;
            var c = captchaUtils.clone(captchaObject);
            c.index = a;
            c.id = captcha.prefix + a;
            c.initCaptcha();
            c.drawCaptcha();
            this.captchaObjects[a] = c
        }
    }
};
captchaObject = {
    id: "",
    index: -1,
    code: "",
    cryptedcode: "",
    cryptedcode_lower: "",
    isRedrawn: false,
    lang: captcha.lang,
    conf_type: captcha.conf_type,
    conf_perturbation: captcha.conf_perturbation,
    conf_num_lines: captcha.conf_num_lines,
    conf_noise_level: captcha.conf_noise_level,
    conf_length: captcha.conf_length,
    conf_case_sensitive: captcha.conf_case_sensitive,
    conf_image_bg_color: captcha.conf_image_bg_color,
    conf_text_color: captcha.conf_text_color,
    conf_line_color: captcha.conf_line_color,
    conf_noise_color: captcha.conf_noise_color,
    conf_text_transparency_percentage: captcha.conf_text_transparency_percentage,
    conf_use_transparent_text: captcha.conf_use_transparent_text,
    conf_background_directory: captcha.conf_background_directory,
    autodetect_protocol: captcha.autodetect_protocol,
    autoinsert_confirmation_field: captcha.autoinsert_confirmation_field,
    id_confirmation_field: captcha.id_confirmation_field,
    label_confirmation_field: captcha.label_confirmation_field,
    initCaptcha: function() {
        this.loadGlobalConfig();
        captcha.loadConfig(this, this.id)
    },
    loadGlobalConfig: function() {
        this.lang = captcha.lang;
        this.conf_type = captcha.conf_type;
        this.conf_perturbation = captcha.conf_perturbation;
        this.conf_num_lines = captcha.conf_num_lines;
        this.conf_noise_level = captcha.conf_noise_level;
        this.conf_length = captcha.conf_length;
        this.conf_case_sensitive = captcha.conf_case_sensitive;
        this.conf_image_bg_color = captcha.conf_image_bg_color;
        this.conf_text_color = captcha.conf_text_color;
        this.conf_line_color = captcha.conf_line_color;
        this.conf_noise_color = captcha.conf_noise_color;
        this.conf_text_transparency_percentage = captcha.conf_text_transparency_percentage;
        this.conf_use_transparent_text = captcha.conf_use_transparent_text;
        this.conf_background_directory = captcha.conf_background_directory;
        this.autodetect_protocol = captcha.autodetect_protocol;
        this.autoinsert_confirmation_field = captcha.autoinsert_confirmation_field;
        this.id_confirmation_field = captcha.id_confirmation_field;
        this.label_confirmation_field = captcha.label_confirmation_field
    },
    getCaptchaValue: function() {
        var b = document.getElementById(this.id + "_img");
        if (typeof b !== null && typeof b.complete === "boolean" && !b.complete) {
            setTimeout((function(d) {
                return function() {
                    d.getCaptchaValue()
                }
            })(this), 500);
            return false
        }
        var a = captcha.server + captcha.path + captcha.path_code;
        var c = new Object;
        c.case_sensitive = this.conf_case_sensitive;
        c.namespace = this.id;
        c[captcha.session_name] = captcha.sid;
        c.index = this.index;
        captchaUtils.JSONP.get(a, c, function(d) {})
    },
    cryptedsecurimage: function(a) {
        this.code = a.code;
        this.cryptedcode = a.cryptedcode;
        this.cryptedcode_lower = a.cryptedcode_lower
    },
    validateCaptcha: function(b) {
        var d = (this.conf_case_sensitive ? this.cryptedcode : this.cryptedcode_lower),
            e = "",
            c = "",
            a = "";
        if (b == null || typeof b === "undefined") {
            if (typeof this.id_confirmation_field === "string" && this.id_confirmation_field.length) {
                a = this.id_confirmation_field
            } else {
                a = "security_code"
            }
            b = document.getElementById(a)
        } else {
            if (typeof b === "string") {
                b = document.getElementById(b)
            }
        } if (b !== null && typeof b === "object" && typeof b.value === "string") {
            e = b.value
        } else {
            if (typeof b === "string") {
                e = b
            }
        } if (!this.conf_case_sensitive) {
            e = e.toLowerCase()
        }
        c = captchaUtils.MD5(e);
        return (d === c)
    },
    clearCaptcha: function() {
        var b = document.getElementById(this.id);
        if (b !== null && typeof b !== "undefined") {
            var a = b.getElementsByTagName("SPAN");
            if (typeof a !== "undefined" && typeof a[0] !== "undefined") {
                b.removeChild(a[0])
            }
            if (typeof a !== "undefined" && typeof a[0] !== "undefined") {
                b.removeChild(a[0])
            }
            a = document.getElementById(this.id).getElementsByTagName("BR");
            if (a !== null && typeof a !== "undefined" && typeof a[0] !== "undefined") {
                b.removeChild(a[0])
            }
        }
    },
    reDraw: function(a, d, b) {
        if (typeof a !== "undefined") {
            if (a == "onkeyup") {
                var c = captchaUtils.keyCheck(d);
                if (c == 13) {
                    this.isRedrawn = true;
                    this.clearCaptcha();
                    this.drawCaptcha("refresh");
                    setTimeout((function(e) {
                        return function() {
                            e.isRedrawn = false
                        }
                    })(this), 500)
                }
            } else {
                if (a == "onclick" && !this.isRedrawn) {
                    this.clearCaptcha();
                    this.drawCaptcha()
                }
            }
        }
    },
    drawCaptcha: function(action) {
        var captcha_container = document.createElement("SPAN");
        captcha_container.className = "captchaContainer";
        var captcha_img = document.createElement("IMG");
        captcha_img.id = this.id + "_img";
        var captcha_img_src = captcha.server + captcha.path + captcha.path_img + "?&" + captcha.session_name + "=" + captcha.sid + captcha.params_img;
        captcha_img_src += "&namespace=" + this.id;
        captcha_img_src += "&type=" + this.conf_type;
        captcha_img_src += "&perturbation=" + this.conf_perturbation;
        captcha_img_src += "&num_lines=" + this.conf_num_lines;
        captcha_img_src += "&noise_level=" + this.conf_noise_level;
        captcha_img_src += "&length=" + this.conf_length;
        captcha_img_src += "&case_sensitive=" + this.conf_case_sensitive;
        captcha_img_src += "&image_bg_color=" + this.conf_image_bg_color;
        captcha_img_src += "&text_color=" + this.conf_text_color;
        captcha_img_src += "&line_color=" + this.conf_line_color;
        captcha_img_src += "&noise_color=" + this.conf_noise_color;
        captcha_img_src += "&background_directory=" + this.conf_background_directory;
        captcha_img_src += "&text_transparency_percentage=" + this.conf_text_transparency_percentage;
        captcha_img_src += "&use_transparent_text=" + this.conf_use_transparent_text;
        captcha_img_src += "&seed=" + Math.random();
        captcha_img.src = captcha_img_src;
        captcha_img.alt = captcha.labels[this.lang]["img"];
        captcha_img.className = "captchaImg";
        captcha_container.appendChild(captcha_img);
        var captcha_readaudio = document.createElement("A");
        captcha_readaudio.href = "javascript:void(0);";
        captcha_readaudio.alt = captcha.labels[this.lang]["read"];
        captcha_readaudio.className = "captchaReadAudio";
        captcha_readaudio.id = this.id + "_readaudio";
        captcha_readaudio.onclick = (function(index) {
            return function() {
                captcha.captchaObjects[index].readCaptcha()
            }
        })(this.index);
        var captcha_readaudio_img = document.createElement("IMG");
        captcha_readaudio_img.src = captcha.server + captcha.path + captcha.path_icon_play;
        captcha_readaudio_img.alt = captcha.labels[this.lang]["read"];
        captcha_readaudio_img.id = this.id + "_img_read";
        captcha_readaudio_img.className = "captchaImgReadAudio";
        captcha_readaudio.appendChild(captcha_readaudio_img);
        captcha_container.appendChild(captcha_readaudio);
        var captcha_br = document.createElement("BR");
        captcha_container.appendChild(captcha_br);
        var captcha_refresh = document.createElement("A");
        captcha_refresh.href = "javascript:void(0);";
        captcha_refresh.alt = captcha.labels[this.lang]["refresh"];
        captcha_refresh.className = "captchaRefresh";
        captcha_refresh.id = this.id + "_refresh";
        captcha_refresh.onclick = (function(index) {
            return function() {
                captcha.captchaObjects[index].reDraw("onclick")
            }
        })(this.index);
        captcha_refresh.onkeydown = (function(index) {
            return function(event) {
                captcha.captchaObjects[index].reDraw("onkeyup", event, "refresh")
            }
        })(this.index);
        var captcha_refresh_img = document.createElement("IMG");
        captcha_refresh_img.src = captcha.server + captcha.path + captcha.path_icon_refresh;
        captcha_refresh_img.alt = captcha.labels[this.lang]["refresh"];
        captcha_refresh_img.className = "captchaImgRefresh";
        captcha_refresh.appendChild(captcha_refresh_img);
        captcha_container.appendChild(captcha_refresh);
        var captcha_object_desc = document.createElement("P");
        captcha_object_desc.className = "captchaOffScreen";
        captcha_object_desc.id = this.id + "_object_desc";
        captcha_object_desc.innerHTML = "SWF Object : " + captcha.labels[this.lang]["read"];
        var captcha_object = document.createElement("OBJECT");
        var isMSIE = /*@cc_on!@*/ false;
        captcha_object.className = "captchaObject";
        captcha_object.id = this.id + "_object";
        if (!isMSIE) {
            captcha_object.appendChild(captcha_object_desc)
        }
        captcha_container.appendChild(captcha_object);
        var captcha_hidden = document.createElement("INPUT");
        captcha_hidden.type = "hidden";
        captcha_hidden.name = captcha.session_name;
        captcha_hidden.value = captcha.sid;
        captcha_container.appendChild(captcha_hidden);
        var captcha_hidden_namespace = document.createElement("INPUT");
        captcha_hidden_namespace.type = "hidden";
        captcha_hidden_namespace.name = "namespace";
        captcha_hidden_namespace.value = this.id;
        captcha_container.appendChild(captcha_hidden_namespace);
        var captcha_br_cr = document.createElement("BR");
        captcha_br_cr.className = "captchaBr";
        var captchaspan = document.getElementById(this.id);
        if (captchaspan !== null && typeof captchaspan !== "undefined") {
            captchaspan.appendChild(captcha_container);
            captchaspan.appendChild(captcha_br_cr)
        }
        if (typeof action !== "undefined") {
            if (action == "refresh") {
                var elem = document.getElementById(this.id + "_refresh")
            }
            if (action == "readaudio") {
                var elem = document.getElementById(this.id + "_readaudio")
            }
            if (elem !== null && typeof elem !== "undefined") {
                elem.focus()
            }
        }
        this.drawConfirmationField();
        setTimeout((function(obj) {
            return function() {
                obj.getCaptchaValue()
            }
        })(this), 500)
    },
    drawConfirmationField: function() {
        if (!this.autoinsert_confirmation_field) {
            return false
        }
        var a = document.getElementById("security_code");
        if (a !== null && typeof a !== "undefined" && this.id_confirmation_field === "security_code") {
            return false
        }
        var c = document.createElement("SPAN");
        c.className = "captchaConfirmation";
        var d = document.createElement("LABEL");
        d.htmlFor = this.id_confirmation_field;
        d.className = "captchaConfirmationLabel";
        d.innerHTML = this.conf_type == "string" ? captcha.labels[this.lang]["type"]["string"] : captcha.labels[this.lang]["type"]["math"];
        if (this.label_confirmation_field !== null && typeof this.label_confirmation_field === "string") {
            d.innerHTML = this.label_confirmation_field
        }
        var b = document.createElement("INPUT");
        b.type = "text";
        b.name = this.id_confirmation_field;
        b.id = this.id_confirmation_field;
        var e = document.createElement("INPUT");
        e.type = "hidden";
        e.name = "captcha_field_name";
        e.id = "captcha_field_name";
        e.value = this.id_confirmation_field;
        c.appendChild(d);
        c.appendChild(b);
        c.appendChild(e);
        var f = document.getElementById(this.id);
        if (f !== null && typeof f !== "undefined") {
            f.appendChild(c)
        }
    },
    readCaptcha: function() {
        var captcha_audio = captcha.server + captcha.path + captcha.path_swf + "?&audio_file=" + captcha.server + captcha.path + captcha.path_audio + "%3F%26" + captcha.session_name + "%3D" + captcha.sid + "%26namespace%3D" + this.id + "&seed=" + Math.random();
        var target_element = document.getElementById(this.id + "_object"),
            isMSIE = /*@cc_on!@*/ false,
            obj = (isMSIE) ? captchaUtils.createIeObject(captcha_audio, "captchaObject", this.id + "_object") : document.createElement("OBJECT");
        if (!isMSIE) {
            obj.setAttribute("id", this.id + "_object");
            obj.setAttribute("type", "application/x-shockwave-flash");
            obj.setAttribute("data", captcha_audio);
            obj.setAttribute("class", "captchaObject");
            var captcha_object_desc = document.createElement("P");
            captcha_object_desc.className = "captchaOffScreen";
            captcha_object_desc.id = this.id + "_object_desc";
            captcha_object_desc.innerHTML = "SWF Object : " + captcha.labels[this.lang]["read"];
            obj.appendChild(captcha_object_desc)
        }
        var param_flashvars = document.createElement("PARAM");
        param_flashvars.setAttribute("name", "movie");
        param_flashvars.setAttribute("value", captcha_audio);
        obj.appendChild(param_flashvars);
        if (target_element !== null && typeof target_element !== "undefined") {
            target_element.parentNode.replaceChild(obj, target_element)
        }
        var captcha_readaudio_img = document.getElementById(this.id + "_img_read");
        if (captcha_readaudio_img !== null && typeof captcha_readaudio_img !== "undefined") {
            captcha_readaudio_img.src = captcha.server + captcha.path + captcha.path_icon_loading;
            captcha_readaudio_img.className = "captchaImgReadAudioLoading";
            setTimeout(function() {
                captcha_readaudio_img.src = captcha.server + captcha.path + captcha.path_icon_play;
                captcha_readaudio_img.className = "captchaImgReadAudio"
            }, 3000)
        }
    }
};
captchaUtils.addEvent(window, "load", function() {
    captcha.init()
});
