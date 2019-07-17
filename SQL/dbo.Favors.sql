CREATE TABLE [dbo].[Favors] (
    [Id_favor]     INT      IDENTITY (1, 1) NOT NULL,
    [f_start_date] DATETIME NOT NULL,
    [f_end_date]   DATETIME NOT NULL,
    [Id_people]    INT      NOT NULL,
    [Id_book]      INT      NOT NULL,
    [f_return]     BIT      NULL,
    [f_lose]       BIT      NULL,
    PRIMARY KEY CLUSTERED ([Id_favor] ASC),
    CONSTRAINT [FK_Favors_Books] FOREIGN KEY ([Id_book]) REFERENCES [dbo].[Books] ([Id_book]),
    CONSTRAINT [FK_Favors_Client] FOREIGN KEY ([Id_people]) REFERENCES [dbo].[Client] ([Id_people])
);

