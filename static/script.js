// listree();

var ls = [
    ['bold', 'italic', 'underline'],
    ['code-block'],
    [{'header': [1, 2, 3, 4, 5, 6, false]}],
    ['image', 'link'],
    [{'color': []}, {'background': []}],

]
var editor = new Quill('#editor', {
    modules: {
        toolbar: ls
    },
    theme: 'snow'
});
let output = document.querySelector("#output");
let files = document.querySelector("#files");
let fn = document.querySelector("#fn");

function uploadUrl(sendObj, end_point) {
    fetch("http://127.0.0.1:5000" + end_point, {
        body: JSON.stringify(sendObj),
        headers: {
            "Content-Type": "application/json",
        },
        method: "post",
    })
        .then((response) => response.json())
        .then((data) => {
            output.innerHTML = JSON.stringify(data);
        })
        .catch((err) => {
            output.innerHTML = JSON.stringify(err);
        });
}

var my_arr = []

function makeList(obj, xpath) {
    if (obj['type'] === 'file') {
        my_arr.push(`<li><a href="#" onclick="myFun('${xpath}/${obj['name']}')">${obj['name']}</a></li>`)
    } else {
        my_arr.push(`<li><span class="caret">${obj['name']}</span><ul class="nested">`)
        for (let i = 0; i < obj['children'].length; i++) {
            makeList(obj['children'][i], xpath + '/' + obj['name'])
        }
        my_arr.push('</ul></li>')
    }
}

function get_data(end_point) {
    fetch("http://127.0.0.1:5000" + end_point, {
        method: "get",
    })
        .then((response) => response.json())
        .then((data) => {
            files.innerHTML= ''
            my_arr = []
            makeList(data, '')
            files.innerHTML = my_arr.join("");
            myFun1()
        })
        .catch((err) => {
            console.log(err);
            output.innerHTML = JSON.stringify(err);
        });
}

function get_content(sendObj, end_point) {
    fetch("http://127.0.0.1:5000" + end_point, {
        body: JSON.stringify(sendObj),
        headers: {
            "Content-Type": "application/json",
        },
        method: "post"
    })
        .then((response) => response.json())
        .then((data) => {
            output.innerHTML = '';
            fn.value = sendObj['path']
            editor.root.innerHTML = data['data'];
        })
        .catch((err) => {
            console.log(err);
            output.innerHTML = JSON.stringify(err);
        });
}

let xmlBtn = document.querySelector("#my_submit");
xmlBtn.addEventListener("click", function () {
    let justHtml = editor.root.innerHTML;
    let sendObj = {
        fn: document.querySelector("#fn").value,
        data: justHtml
    };
    uploadUrl(sendObj, "/save");

});

function myFun1() {
    console.log('myFun1')
    var toggler = document.getElementsByClassName("caret");
    var i;

    for (i = 0; i < toggler.length; i++) {
        toggler[i].addEventListener("click", function () {
            this.parentElement.querySelector(".nested").classList.toggle("active");
            this.classList.toggle("caret-down");
        });
    }
}

function myFun(path) {
    get_content({path: path}, "/view");
}