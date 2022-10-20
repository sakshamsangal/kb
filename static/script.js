var ls = [
    ['bold', 'italic', 'underline'],
    ['blockquote', 'code-block'],
    [{'header': [1, 2, 3, 4, 5, 6, false]}],
    ['image', 'link'],
    [{'color': []}, {'background': []}],

]
var folders = ''
var editor = new Quill('#editor', {
    modules: {
        toolbar: ls
    },
    theme: 'snow'
});

let xmlBtn = document.querySelector("#my_submit");
let output = document.querySelector("#output");
let files = document.querySelector("#folders");
let fn = document.querySelector("#fn");
let search_id = document.getElementById('filterInput');

function uploadUrl(sendObj, end_point) {
    fetch("http://127.0.0.1:5000" + end_point, {
        body: JSON.stringify(sendObj),
        headers: {
            "Content-Type": "application/json",
        },
        method: "post"
    })
        .then((response) => response.json())
        .then((data) => {
            output.innerHTML = JSON.stringify(data);
            setTimeout(() => {
                output.innerHTML = ''
                // output.style.display = 'none';
            }, 2000);
        })
        .catch((err) => {
            output.innerHTML = JSON.stringify(err);
        });
}

function displayJsonTree(data) {
    var htmlRetStr = "<ul class='folder-container'>";
    for (var key in data) {
        if (typeof (data[key]) == 'object' && data[key] != null) {
            htmlRetStr += displayJsonTree(data[key]);
            htmlRetStr += '</ul></li>';
        } else if (data[key] === 'dir') {
            htmlRetStr += "<li class='folder-item'><i class='bi bi-folder'></i> " + data["name"] + "</li><li class='folder-wrapper'>";
        } else if (key === 'name' && data['type'] !== 'dir') {
            htmlRetStr += `<li class='file-item' onclick="myFun('${data['xpath']}/${data['name']}')"><i class="bi bi-card-list"></i> ` + data['name'] + "</li>";
        }
    }
    return (htmlRetStr);
}

function filterJson(data, string) {
    arr = [];
    for (var key in data)
        if (typeof (data[key]) == 'object' && data[key] != null) {
            if (data['name'].indexOf(string) <= -1) {
                for (var i = 0; i < data.children.length; i++) {
                    arr = arr.concat(filterJson(data.children[i], string));
                }
                return arr;
            }
        } else {
            if (data['name'].indexOf(string) > -1) {
                arr = arr.concat(data);
                return arr;
            }
        }
}

function solve() {
    let toSearch = search_id.value;
    if (toSearch.length === 0) {
        files.innerHTML = displayJsonTree(folders);
    } else {
        let str = "Searching for: " + search_id.value + "\n";
        files.innerHTML = str + displayJsonTree(filterJson(folders, search_id.value));
    }
    myFun1()
}

function get_data(end_point) {
    fetch("http://127.0.0.1:5000" + end_point, {
        method: "get",
    })
        .then((response) => response.json())
        .then((data) => {
            // files.innerHTML = ''
            files.innerHTML = displayJsonTree(data);
            folders = data
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
    var toggler = document.getElementsByClassName("folder-item");
    var i;
    for (i = 0; i < toggler.length; i++) {
        toggler[i].addEventListener("click", function () {
            this.parentElement.querySelector(".folder-wrapper").classList.toggle("nested");
        });
    }
}

function myFun(path) {
    console.log(path)
    get_content({path: '.' + path}, "/view");
}