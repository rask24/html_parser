//{
//	"tag": "html",
//	"child": [
//		{
//			"tag": "head",
//			"child": [
//				{
//					"tag": "title",
//					"child": {
//						"content": "sample page"
//					}
//				}
//			]
//		},
//		{
//			"tag": "body",
//			"child": [
//				{
//					"tag": "h1",
//					"child": {
//						"content": "SAMPLE"
//					}
//				},
//				{
//					"tag": "p",
//					"child": {
//						"content": "This is a sample page!!"
//					}
//				}
//			]
//		}
//	]
//}

const colors = require('colors');
const dom = require('../output/ideal.json');

if (dom.tag !== 'html' || dom.child[0].tag !== 'head' || dom.child[1].tag !== 'body') {
	console.log("invalid form of html");
	process.exit(1);
}

const head = dom.child[0];
const body = dom.child[1];
const isHeading = (tag) => {
	switch (tag) {
		case 'h1':
		case 'h2':
		case 'h3':
		case 'h4':
		case 'h5':
		case 'h6':
			return true;
	}
	return false;
};
const printElement = (element) => {
	if (isHeading(element.tag)) {
		console.log(element.child.content.bold);
	} else if (element.tag === 'p') {
		console.log(element.child.content.underline);
	} else {
		console.log(element.child.content);
	}
}

head.child.forEach((val) => {
	if (val.tag === 'title') {
		console.log(`==========${val.child.content}==========`.inverse);
	}
});

body.child.forEach((element) => {
	printElement(element);
});
