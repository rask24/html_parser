const colors = require('colors');
const dom = require('./kneeling.json');

if (dom.tag !== 'html' || dom.child[0].tag !== 'head' || dom.child[1].tag !== 'body') {
	console.log("invalid form of html");
	process.exit(1);
}

const head = dom.child[0];
const body = dom.child[1];
const printHeading = (element) => {
	const content = element.child.content;

	switch (element.tag) {
		case 'h1':
			console.log(content.bold.blue);
			break;
		case 'h2':
			console.log(content.bold.cyan);
			break;
		case 'h3':
			console.log(content.bold.yellow);
			break;
		case 'h4':
			console.log(content.bold.red);
			break;
		case 'h5':
			console.log(content.bold.magenta);
			break;
		case 'h6':
			console.log(content.bold.gray);
			break;
		default:
			console.log(content);
	}
};

const printElement = (element) => {
	if (element.tag[0] === 'h') {
		printHeading(element);
		console.log("");
	} else if (element.tag === 'p') {
		console.log(element.child.content);
		console.log("");
	} else if (element.tag === 'ul') {
		element.child.forEach((item) => {
			console.log('・' + item.child.content);
		});
		console.log("");
	} else {
		console.log(element.child.content);
	}
};

head.child.forEach((val) => {
	if (val.tag === 'title') {
		console.log(`TITLE: ${val.child.content}`.inverse);
	}
	console.log("");
});

body.child.forEach((element) => {
	printElement(element);
});

