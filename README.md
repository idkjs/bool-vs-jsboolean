## Notes

1.  Added bs-platform to dev dependencies.
2.  Fixed Graphql version # in deps.
3.  Uncommented code which throws error.

## Reproducing error.

Run `yarn` then `yarn start`.

Should produce this error:

```sh
./src/index.re
Module build failed: Error: We've found a bug for you!
  /Users/prisc_000/Downloads/bool-vs-jsboolean/src/components/FeedPage.re 75:23-77:23

  73 ┆         )
  74 ┆      |> ReasonReact.arrayToElement */
  75 ┆   |> Array.mapi((index, post) =>
  76 ┆        <PostItem post key=(index |> string_of_int) />
  77 ┆      )
  78 ┆   |> ReasonReact.arrayToElement
  79 ┆ }

  This has type:
    array(Js.t(({.. id: string, isPublished: bool, text: string,
                  title: string}
                as 'a))) =>
    array(ReasonReact.reactElement)
  But somewhere wanted:
    Js.Array.t({. "id": string, "isPublished": Js.boolean, "text": string,
                 "title": string}) =>
    'b

  The incompatible parts:
    array(Js.t('a))
    vs
    Js.Array.t({. "id": string, "isPublished": Js.boolean, "text": string,
                 "title": string})
      (defined as
      array({. "id": string, "isPublished": Js.boolean, "text": string,
              "title": string}))
  Types for method isPublished are incompatible

    at <anonymous>rc/components/CreatePage.cmj
```
