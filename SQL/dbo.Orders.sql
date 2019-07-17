CREATE TABLE [dbo].[Orders] (
    [Id_order]     INT      IDENTITY (1, 1) NOT NULL,
    [o_count]      INT      NOT NULL,
    [o_s_costs]    INT      NOT NULL,
    [o_date_order] DATETIME NOT NULL,
    [o_date_end]   DATETIME NOT NULL,
    [o_ready]      BIT      NULL,
    [o_cancel]     BIT      NULL,
    [Id_suppliers] INT      NOT NULL,
    [Id_book]      INT      NOT NULL,
    PRIMARY KEY CLUSTERED ([Id_order] ASC),
    CONSTRAINT [FK_Orders_Books] FOREIGN KEY ([Id_book]) REFERENCES [dbo].[Books] ([Id_book]),
    CONSTRAINT [FK_Orders_Suppliers] FOREIGN KEY ([Id_suppliers]) REFERENCES [dbo].[Suppliers] ([Id_suppliers])
);

